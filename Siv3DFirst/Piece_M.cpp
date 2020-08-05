#include "Piece_M.h"

Piece_M::Piece_M(TFPtr transform) : Piece::Piece(transform)
{
	//
}

void Piece_M::Update()
{
	//
}

void Piece_M::Draw()
{
	DrawBG();
	DrawTriangle(Center(), LD(), LU());
	DrawTriangle(Center(), RU(), RD());
	DrawTriangle(Center(), RD(), LD());
}

bool Piece_M::CanJoint(enum Direction direction)
{
	if (Direction_rotated(RIGHT, this->Direction()) == direction) return true;
	if (Direction_rotated(LEFT,  this->Direction()) == direction) return true;
	if (Direction_rotated(DOWN,  this->Direction()) == direction) return true;
	return false;
}
