#include "Piece_L.h"

void Piece_L::Update()
{

}

void Piece_L::Draw(std::shared_ptr<Transform> transform)
{
	DrawBG(transform);
	DrawTriangle(LU(transform), RD(transform), LD(transform));
}

bool Piece_L::CanJoint(enum Direction direction)
{
	if (Direction_rotated(LEFT, this->Direction()) == direction) return true;
	if (Direction_rotated(DOWN, this->Direction()) == direction) return true;
	return false;
}
