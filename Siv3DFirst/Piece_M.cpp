#include "Piece_M.h"

void Piece_M::Update()
{
	//
}

void Piece_M::Draw(TFPtr transform)
{
	DrawBG(transform);
	DrawTriangle(Center(transform), LD(transform), LU(transform));
	DrawTriangle(Center(transform), RU(transform), RD(transform));
	DrawTriangle(Center(transform), RD(transform), LD(transform));
}

bool Piece_M::CanJoint(enum Direction direction)
{
	if (Direction_rotated(RIGHT, this->Direction()) == direction) return true;
	if (Direction_rotated(LEFT,  this->Direction()) == direction) return true;
	if (Direction_rotated(DOWN,  this->Direction()) == direction) return true;
	return false;
}
