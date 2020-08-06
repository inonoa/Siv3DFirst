#include "Piece_M.h"

Piece_M::Piece_M() : PieceType::PieceType()
{
	//
}


void Piece_M::Draw()
{
	piece->DrawBG();
	piece->DrawTriangle(piece->Center(), piece->LD(), piece->LU());
	piece->DrawTriangle(piece->Center(), piece->RU(), piece->RD());
	piece->DrawTriangle(piece->Center(), piece->RD(), piece->LD());
}

bool Piece_M::CanJoint(enum Direction direction)
{
	if (Direction_rotated(RIGHT, piece->Direction()) == direction) return true;
	if (Direction_rotated(LEFT,  piece->Direction()) == direction) return true;
	if (Direction_rotated(DOWN,  piece->Direction()) == direction) return true;
	return false;
}
