#include "Piece_L.h"

void Piece_L::Update()
{
	//
}

void Piece_L::Draw(std::shared_ptr<Transform> transform)
{
	DrawBG(transform);

	switch (direction)
	{
	case Direction::RIGHT:
		DrawTriangle(RU(transform), RD(transform), LD(transform));
		break;
	case Direction::DOWN:
		DrawTriangle(LU(transform), RD(transform), LD(transform));
		break;
	case Direction::LEFT:
		DrawTriangle(LU(transform), RU(transform), LD(transform));
		break;
	case Direction::UP:
		DrawTriangle(LU(transform), RU(transform), RD(transform));
		break;
	}
}
