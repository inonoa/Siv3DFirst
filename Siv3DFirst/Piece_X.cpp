#include "Piece_X.h"

Piece_X::Piece_X() : PieceType::PieceType()
{
	//
}


void Piece_X::Draw()
{
	piece->DrawBG();
	piece->DrawTriangle(piece->Center(), piece->RU(), piece->RD());
	piece->DrawTriangle(piece->Center(), piece->LD(), piece->LU());
}

bool Piece_X::CanJoint(enum Direction direction)
{
	if (Direction_rotated(RIGHT, piece->Direction()) == direction) return true;
	if (Direction_rotated(LEFT,  piece->Direction()) == direction) return true;
	return false;
}
