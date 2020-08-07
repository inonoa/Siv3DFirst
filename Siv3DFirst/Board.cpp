#include "Board.h"
#include "Piece_v.h"
#include <Siv3D.hpp>
#include <memory>
#include "PieceTypes.h"
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
	HandleInput();
	
	for (int i = 0; i < pieces->size(); i ++)
	{
		Array<shared_ptr<Piece>>* arr = pieces.get();
		(*arr)[i]->Update();
	}

	Array<shared_ptr<Piece>> falling = pieces->filter([](shared_ptr<Piece> p) { return p->IsFalling(); });
	Array<shared_ptr<Piece>> on_tile = pieces->filter([](shared_ptr<Piece> p) { return p->IsOnTile(); });

	//不十分
	for (shared_ptr<Piece> p_falling : falling)
	{
		for (shared_ptr<Piece> p_on_tile : on_tile)
		{

			Vec2 dist_vec = p_on_tile->GetTF()->LocalPos() - p_falling->GetTF()->LocalPos();
			if ((Math::Abs(dist_vec.x) < 0.01) && (dist_vec.y <= 50))
			{
				p_falling->Land(p_falling->PosOnBoard().x, p_on_tile->PosOnBoard().y - 1);
				tiles[p_on_tile->PosOnBoard().y - 1][p_falling->PosOnBoard().x]->SetPiece(p_falling);
				Vec2 tilePos = tiles[p_on_tile->PosOnBoard().y - 1][p_falling->PosOnBoard().x]
					           ->GetTransform()->WorldPos();
				p_falling->GetTF()->SetWorldPos(tilePos.x, tilePos.y);
			}
		}

		if (p_falling->GetTF()->LocalPos().y >= gridsize.y / 2.0 * 50 - 25)
		{
			Print << U"着地";
			p_falling->Land(p_falling->PosOnBoard().x, gridsize.y - 1);
			tiles[gridsize.y - 1][p_falling->PosOnBoard().x]->SetPiece(p_falling);
			Vec2 tilePos = tiles[gridsize.y - 1][p_falling->PosOnBoard().x]
				->GetTransform()->WorldPos();
			p_falling->GetTF()->SetWorldPos(tilePos.x, tilePos.y);
		}
	}
	
	Array<shared_ptr<Piece>> toBeRemoved;
	for (shared_ptr<Piece> p_on_tile : on_tile)
	{
		if(tiles[p_on_tile->PosOnBoard().y][p_on_tile->PosOnBoard().x]->GetPiece() == nullptr){ continue; }
		Array<Array<bool>> checked(gridsize.y, Array<bool>(gridsize.x, false));
		if (FormFigure(&checked, p_on_tile->PosOnBoard().x, p_on_tile->PosOnBoard().y))
		{
			for(int i = 0; i < gridsize.y; i++)
			{
				for(int j = 0; j < gridsize.x; j++)
				{
					if(checked[i][j])
					{
						toBeRemoved << tiles[i][j]->GetPiece();
						tiles[i][j]->RemovePiece();
					}
				}
			}
		}
	}
	for(auto p : toBeRemoved)
	{
		Vector2D<int> pos = p->PosOnBoard();
		for(int y = pos.y - 1; y > -1; y--){
			if(tiles[y][pos.x]->GetPiece() != nullptr)
			{
				tiles[y][pos.x]->GetPiece()->LoseGround();
				tiles[y][pos.x]->RemovePiece();
			}
		}
	}
	pieces->remove_if([=](auto p){ return toBeRemoved.includes(p); });
}

void Board::HandleInput()
{
	if (KeyRight.down()){
		selected = Vector2D<int>(selected.x == tiles[0].size() - 1 ? selected.x : selected.x + 1, selected.y);
	}
	if (KeyLeft.down()){
		selected = Vector2D<int>(selected.x == 0 ? selected.x : selected.x - 1, selected.y);
	}
	if (KeyUp.down()){
		selected = Vector2D<int>(selected.x, selected.y == 0 ? selected.y : selected.y - 1);
	}
	if (KeyDown.down()){
		selected = Vector2D<int>(selected.x, selected.y == tiles.size() - 1 ? selected.y : selected.y + 1);
	}


	if (KeyX.down()){
		shared_ptr<Piece> p = tiles[selected.y][selected.x]->GetPiece();
		if(p) p->Rotate(true);
	}
	if (KeyC.down()){
		shared_ptr<Piece> p = tiles[selected.y][selected.x]->GetPiece();
		if(p) p->Rotate(false);
	}

	if (KeyF.down()){
		SpawnPiece(selected.x);
	}
}

bool Board::FormFigure(Array<Array<bool>>* checked, int x, int y)
{

	(*checked)[y][x] = true;

	bool ans = true;

	if (tiles[y][x]->GetPiece()->CanJoint(Direction::RIGHT))
	{
		if (x < gridsize.x - 1)
		{
			if (tiles[y][x + 1]->GetPiece() == nullptr){ ans = false; }
			else
			{
				if (!tiles[y][x + 1]->GetPiece()->CanJoint(Direction::LEFT)) { ans = false; }
				else
				{
					if (!(*checked)[y][x + 1])
					{
						ans &= FormFigure(checked, x + 1, y);
					}
				}
			}
		}
	}
	if (tiles[y][x]->GetPiece()->CanJoint(Direction::LEFT))
	{
		if (x > 0)
		{
			if (tiles[y][x - 1]->GetPiece() == nullptr) { ans = false; }
			else
			{
				if (!tiles[y][x - 1]->GetPiece()->CanJoint(Direction::RIGHT)) { ans = false; }
				else
				{
					if (!(*checked)[y][x - 1])
					{
						ans &= FormFigure(checked, x - 1, y);
					}
				}
			}
		}
	}
	if (tiles[y][x]->GetPiece()->CanJoint(Direction::UP))
	{
		if (y > 0)
		{
			if (tiles[y - 1][x]->GetPiece() == nullptr) { ans = false; }
			else
			{
				if (!tiles[y - 1][x]->GetPiece()->CanJoint(Direction::DOWN)) { ans = false; }
				else
				{
					if (!(*checked)[y - 1][x])
					{
						ans &= FormFigure(checked, x, y - 1);
					}
				}
			}
		}
		else
		{
			ans = false;
		}
	}
	if (tiles[y][x]->GetPiece()->CanJoint(Direction::DOWN))
	{
		if (y < gridsize.y - 1)
		{
			if (tiles[y + 1][x]->GetPiece() == nullptr) { ans = false; }
			else
			{
				if (!tiles[y + 1][x]->GetPiece()->CanJoint(Direction::UP)) { ans = false; }
				else
				{
					if (!(*checked)[y + 1][x])
					{
						ans &= FormFigure(checked, x, y + 1);
					}
				}
			}
		}
		else
		{
			ans = false;
		}
	}

	return ans;
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

	for (int i = 0; i < pieces->size(); i++)
	{
		Array<shared_ptr<Piece>> arr = *(pieces.get());
		arr[i]->Draw();
	}

	Vec2 selectedPos = tiles[selected.y][selected.x]->GetTransform()->WorldPos();
	Rect(selectedPos.x - 26,
		selectedPos.y - 26,
		52,
		52)
		.draw(ColorF(0.1f, 0.2f, 0.9f, 0.2f));
}

void Board::SpawnPiece(int x)
{
	Vec2 spawnPos = tiles[0][selected.x]->GetTransform()->LocalPos() - Vec2(0, 50);
	TFPtr tf = MakeShared<Transform>(this->transform, spawnPos);

	shared_ptr<PieceType> type = RandomPiece();

	shared_ptr<Piece> piece = MakeShared<Piece>(tf, type, x);
	type->SetPiece(piece);
	pieces.get()->operator<<(piece);
}

shared_ptr<PieceType> Board::RandomPiece()
{
	int rd = Random<int>(0, 5);
	switch (rd)
	{
	case 0:
		return MakeShared<Piece_v>();
	case 1:
		return MakeShared<Piece_L>();
	case 2:
		return MakeShared<Piece_M>();
	// case 3:
	// 	  return MakeShared<Piece_X>();
	// case 4:
	// 	  return MakeShared<Piece_Q>();
	default:
		return RandomPiece();
	}
}
