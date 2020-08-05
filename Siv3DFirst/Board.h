#pragma once

#include <Siv3D.hpp>
#include "Tile.h"

using namespace std;

using PiecesArray = shared_ptr<Array<std::shared_ptr<Piece>>>;

class Board
{
public:
	Board(int width, int height);
	std::shared_ptr<Tile> GetTile(int x, int y);
	void SpawnPiece(int x);
	void Update();
	void Draw();

private:
	Array<Array<std::shared_ptr<Tile>>> tiles;
	Vector2D<int> selected;
	shared_ptr<Transform> transform;
	PiecesArray pieces_falling;
	PiecesArray pieces_on_tile;
};

