#pragma once

#include <Siv3D.hpp>
#include "Tile.h"

using namespace std;

using PiecesArray = shared_ptr<Array<std::shared_ptr<Piece>>>;

class Board
{
public:
	Board(int width, int height, double spawnSpan);
	std::shared_ptr<Tile> GetTile(int x, int y);
	void SpawnPiece(int x);
	void Update();
	void Draw();
	bool FormFigure(Array<Array<bool>>* checked_, int x, int y);

private:
	Array<Array<std::shared_ptr<Tile>>> tiles;
	Vector2D<int> selected;
	Vector2D<int> gridsize;
	shared_ptr<Transform> transform;
	PiecesArray pieces;
	void HandleInput();
	shared_ptr<PieceType> RandomPiece();
	double time;
	double time_after_spawn;
	double spawnSpan;
};

