#include "Piece_v.h"

Piece_v::Piece_v(TFPtr transform) : Piece::Piece(transform)
{
	//
}

void Piece_v::Update()
{
	//
}

void Piece_v::Draw(std::shared_ptr<class Transform> transform)
{
	DrawBG(transform);
	DrawTriangle(Center(transform), LU(transform), RU(transform));
}

bool Piece_v::CanJoint(enum Direction direction)
{
	if (Direction_rotated(UP, this->Direction()) == direction) return true;
	return false;
}