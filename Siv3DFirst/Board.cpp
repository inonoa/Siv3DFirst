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
	pieces_falling = MakeShared<Array<std::shared_ptr<Piece>>>();
	pieces_on_tile = MakeShared<Array<std::shared_ptr<Piece>>>();
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

	
	for (int i = 0; i < pieces_falling->size(); i ++)
	{
		Array<shared_ptr<Piece>>* arr = pieces_falling.get();
		(*arr)[i]->Fall();
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

	for (int i = 0; i < pieces_falling->size(); i++)
	{
		Array<shared_ptr<Piece>>* arr = pieces_falling.get();
		(*arr)[i]->Draw();
	}
}

void Board::SpawnPiece(int x)
{
	Vec2 spawnPos = tiles[0][selected.x]->GetTransform()->LocalPos() - Vec2(0, 50);
	TFPtr tf = MakeShared<Transform>(this->transform, spawnPos);
	shared_ptr<PieceType> type = MakeShared<Piece_v>();
	shared_ptr<Piece> piece = MakeShared<Piece>(tf, type);
	type->SetPiece(piece);
	pieces_falling.get()->operator<<(piece);
}
