#include "Piece_L.h"

Piece_L::Piece_L() : PieceType::PieceType()
{
	//
}

void Piece_L::Draw()
{
	piece->DrawBG();
	piece->DrawTriangle(piece->LU(), piece->RD(), piece->LD());
}

bool Piece_L::CanJoint(enum Direction direction)
{
	if (Direction_rotated(LEFT, piece->Direction()) == direction) return true;
	if (Direction_rotated(DOWN, piece->Direction()) == direction) return true;
	return false;
}
