#pragma once
#include "Transform.h"
#include "Piece.h"
#include <memory>

class Tile
{
public:
	Tile(std::shared_ptr<Transform> parent, Vec2 localPos);
	void Update();
	void Draw();
	std::shared_ptr<Piece> GetPiece();
	std::shared_ptr<Transform> GetTransform();
	void SetPiece(std::shared_ptr<Piece> piece);

private:
	std::shared_ptr<Transform> transform;
	std::shared_ptr<Piece> piece;
	void RandomGenerate();
};

