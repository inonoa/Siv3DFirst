#include "Board.h"

Board::Board(int width, int height)
{
	this->tiles = Array<Array<Tile*>>::IndexedGenerate(
		height,
		[=](int i) -> Array<Tile*>
		{
			return Array<Tile*>::IndexedGenerate(
				width, [=](int j) 
				{
					//0‚¶‚á‚È‚¢‚æ
					Tile tile(nullptr, Vec2(15 + 50 * j, 15 + 50 * i));
					return &tile;
				}
			);
		}
	);
	this->selected = Vector2D<int>(0, 0);
}

Tile* Board::GetTile(int x, int y)
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

	Rect(14 + 50 * selected.x, 14 + 50 * selected.y, 52, 52).draw(ColorF(0.2f, 0, 0.8f, 0.2f));
}
