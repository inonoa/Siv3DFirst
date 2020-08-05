#include "Piece_Q.h"

void Piece_Q::Update()
{
	//
}

void Piece_Q::Draw(TFPtr transform)
{
	Vec2 pos_bound = transform->WorldPos() - Vec2(24, 24);
	Rect(pos_bound.x, pos_bound.y, 48, 48).draw(Piece::GREEN);
}

bool Piece_Q::CanJoint(enum Direction direction)
{
	return true;
}
