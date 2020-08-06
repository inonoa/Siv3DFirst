#include "Piece_v.h"

Piece_v::Piece_v() : PieceType::PieceType()
{
	//
}

void Piece_v::Draw()
{
	piece->DrawBG();
	piece->DrawTriangle(piece->Center(), piece->LU(), piece->RU());
}

bool Piece_v::CanJoint(enum Direction direction)
{
	if (Direction_rotated(UP, piece->Direction()) == direction) return true;
	return false;
}
