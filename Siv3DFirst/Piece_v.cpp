#include "Piece_v.h"

Piece_v::Piece_v(TFPtr transform) : Piece::Piece(transform)
{
	//
}

void Piece_v::Update()
{
	//
}

void Piece_v::Draw()
{
	DrawBG();
	DrawTriangle(Center(), LU(), RU());
}

bool Piece_v::CanJoint(enum Direction direction)
{
	if (Direction_rotated(UP, this->Direction()) == direction) return true;
	return false;
}