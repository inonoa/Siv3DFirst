#include "Piece_v.h"

void Piece_v::Update()
{
	//
}

void Piece_v::Draw(std::shared_ptr<Transform> transform)
{
	DrawBG(transform);
	switch (direction)
	{
	case Direction::RIGHT:
		DrawTriangle(Center(transform), RU(transform), RD(transform));
		break;
	case Direction::UP:
		DrawTriangle(Center(transform), LU(transform), RU(transform));
		break;
	case Direction::LEFT:
		DrawTriangle(Center(transform), LD(transform), LU(transform));
		break;
	case Direction::DOWN:
		DrawTriangle(Center(transform), LD(transform), RD(transform));
		break;
	default:
		break;
	}
}
