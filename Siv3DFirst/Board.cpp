#include "Board.h"
#include "Piece_v.h"
#include <Siv3D.hpp>
#include <memory>
using namespace std;

Board::Board(int width, int height)
{
	this->transform = MakeUnique<Transform>(nullptr, Scene::Center());
	this->tiles = Array<Array<shared_ptr<Tile>>>::IndexedGenerate(
		height,
		[=](int i)
		{
			return Array<shared_ptr<Tile>>::IndexedGenerate(
				width, [=](int j)
				{
					Vec2 bound = - Vec2(50, 50) * Vec2(width, height) / 2.0 + Vec2(25, 25);
					return MakeShared<Tile>(this->transform, bound + Vec2(50, 50) * Vec2(j, i));
				}
			);
		}
	);
	this->selected = Vector2D<int>(0, 0);
	this->gridsize = Vector2D<int>(width, height);
	pieces = MakeShared<Array<std::shared_ptr<Piece>>>();
}

shared_ptr<Tile> Board::GetTile(int x, int y)
{
	return tiles[y][x];
}

void Board::Update()
{
	if (KeyRight.down())
	{
		selected = Vector2D<int>(selected.x == tiles[0].size() - 1 ? selected.x : selected.x + 1, selected.y);
	}
	if (KeyLeft.down())
	{
		selected = Vector2D<int>(selected.x == 0 ? selected.x : selected.x - 1, selected.y);
	}
	if (KeyUp.down())
	{
		selected = Vector2D<int>(selected.x, selected.y == 0 ? selected.y : selected.y - 1);
	}
	if (KeyDown.down())
	{
		selected = Vector2D<int>(selected.x, selected.y == tiles.size() - 1 ? selected.y : selected.y + 1);
	}


	if (KeyX.down())
	{
		shared_ptr<Piece> p = tiles[selected.y][selected.x]->GetPiece();
		if(p) p->Rotate(true);
	}
	if (KeyC.down())
	{
		shared_ptr<Piece> p = tiles[selected.y][selected.x]->GetPiece();
		if(p) p->Rotate(false);
	}

	if (KeyF.down())
	{
		SpawnPiece(selected.x);
	}

	
	for (int i = 0; i < pieces->size(); i ++)
	{
		Array<shared_ptr<Piece>>* arr = pieces.get();
		(*arr)[i]->Update();
	}

	Array<shared_ptr<Piece>> falling = pieces->filter([](shared_ptr<Piece> p) { return p->IsFalling(); });
	Array<shared_ptr<Piece>> on_tile = pieces->filter([](shared_ptr<Piece> p) { return p->IsOnTile(); });

	//一気に10段とか落ちてきたときに1Fに一段ずつしか着地しない問題？
	for (shared_ptr<Piece> p_falling : falling)
	{
		for (shared_ptr<Piece> p_on_tile : on_tile)
		{

			Vec2 dist_vec = p_on_tile->GetTF()->LocalPos() - p_falling->GetTF()->LocalPos();
			if ((Math::Abs(dist_vec.x) < 0.01) && (dist_vec.y <= 50))
			{
				// 着地！
				p_falling->Land(p_falling->PosOnBoard().x, p_on_tile->PosOnBoard().y - 1);
				tiles[p_on_tile->PosOnBoard().y - 1][p_falling->PosOnBoard().x]->SetPiece(p_falling);
				Vec2 tilePos = tiles[p_on_tile->PosOnBoard().y - 1][p_falling->PosOnBoard().x]
					           ->GetTransform()->WorldPos();
				p_falling->GetTF()->SetWorldPos(tilePos.x, tilePos.y);
			}
		}

		if (p_falling->GetTF()->LocalPos().y >= gridsize.y / 2.0 * 50 - 25)
		{
			//着地！
			Print << U"着地！";
			p_falling->Land(p_falling->PosOnBoard().x, gridsize.y - 1);
			tiles[gridsize.y - 1][p_falling->PosOnBoard().x]->SetPiece(p_falling);
			Vec2 tilePos = tiles[gridsize.y - 1][p_falling->PosOnBoard().x]
				->GetTransform()->WorldPos();
			p_falling->GetTF()->SetWorldPos(tilePos.x, tilePos.y);
		}
	}
}

void Board::Draw() 
{
	for (int i = 0; i < tiles.size(); i++)
	{
		for (int j = 0; j < tiles[i].size(); j++)
		{
			tiles[i][j]->Draw();
		}
	}

	Vec2 selectedPos = tiles[selected.y][selected.x]->GetTransform()->WorldPos();
	Rect(selectedPos.x - 26,
		selectedPos.y - 26,
		52,
		52)
		.draw(ColorF(0.1f, 0.2f, 0.9f, 0.2f));

	for (int i = 0; i < pieces->size(); i++)
	{
		Array<shared_ptr<Piece>>* arr = pieces.get();
		(*arr)[i]->Draw();
	}
}

void Board::SpawnPiece(int x)
{
	Vec2 spawnPos = tiles[0][selected.x]->GetTransform()->LocalPos() - Vec2(0, 50);
	TFPtr tf = MakeShared<Transform>(this->transform, spawnPos);
	shared_ptr<PieceType> type = MakeShared<Piece_v>();
	shared_ptr<Piece> piece = MakeShared<Piece>(tf, type, x);
	type->SetPiece(piece);
	pieces.get()->operator<<(piece);
}
