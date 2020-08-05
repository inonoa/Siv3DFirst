#include "Piece_X.h"

Piece_X::Piece_X(TFPtr transform) : Piece::Piece(transform)
{
	//
}


void Piece_X::Draw()
{
	DrawBG();
	DrawTriangle(Center(), RU(), RD());
	DrawTriangle(Center(), LD(), LU());
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