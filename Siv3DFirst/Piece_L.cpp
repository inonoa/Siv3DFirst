#include "Piece_L.h"
Piece_L::Piece_L(TFPtr transform) : Piece::Piece(transform)
{
	//
}

void Piece_L::Update()
{

}

void Piece_L::Draw()
{
	DrawBG();
	DrawTriangle(LU(), RD(), LD());
}

bool Piece_L::CanJoint(enum Direction direction)
{
	if (Direction_rotated(LEFT, this->Direction()) == direction) return true;
	if (Direction_rotated(DOWN, this->Direction()) == direction) return true;
	return false;
}
