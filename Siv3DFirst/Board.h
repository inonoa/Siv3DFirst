#pragma once

#include <Siv3D.hpp>
#include "Tile.h"

using namespace std;

class Board
{
public:
	Board(int width, int height);
	Tile* GetTile(int x, int y);
	void Update();
	void Draw();

private:
	Array<Array<Tile*>> tiles;
	Vector2D<int> selected;
};

