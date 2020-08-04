#include "Board.h"
using namespace std;

Board::Board(int width, int height)
{
	this->transform = MakeUnique<Transform>(nullptr, Vec2(15, 15));
	this->tiles = Array<Array<shared_ptr<Tile>>>::IndexedGenerate(
		height,
		[=](int i)
		{
			return Array<shared_ptr<Tile>>::IndexedGenerate(
				width, [=](int j) 
				{
					//null‚¶‚á‚È‚¢‚æ
					return MakeShared<Tile>(this->transform, Vec2(50 * j, 50 * i));
				}
			);
		}
	);
	this->selected = Vector2D<int>(0, 0);
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


	Rect(this->transform->WorldPos().x - 1 + 50 * selected.x, this->transform->WorldPos().y - 1 + 50 * selected.y, 52, 52).draw(ColorF(0.2f, 0, 0.8f, 0.2f));
}
