#include "Piece_Q.h"

Piece_Q::Piece_Q() : PieceType::PieceType()
{
	//
}

void Piece_Q::Draw()
{
	Vec2 pos_bound = piece->GetTF()->WorldPos() - Vec2(24, 24);
	Rect(pos_bound.x, pos_bound.y, 48, 48).draw(Piece::GREEN);
}

bool Piece_Q::CanJoint(enum Direction direction)
{
	return true;
}
