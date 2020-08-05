#include "Piece_X.h"

Piece_X::Piece_X(TFPtr transform) : Piece::Piece(transform)
{
	//
}


void Piece_X::Draw(TFPtr transform)
{
	DrawBG(transform);
	DrawTriangle(Center(transform), RU(transform), RD(transform));
	DrawTriangle(Center(transform), LD(transform), LU(transform));
}

void Piece_X::Update()
{
	//
}

bool Piece_X::CanJoint(enum Direction direction)
{
	if (Direction_rotated(RIGHT, this->Direction()) == direction) return true;
	if (Direction_rotated(LEFT, this->Direction()) == direction) return true;
	return false;
}