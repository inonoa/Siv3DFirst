#include "Piece_X.h"

void Piece_X::Draw(TFPtr transform)
{
	DrawBG(transform);
	if ((direction == Direction::RIGHT) || (direction == Direction::LEFT))
	{
		DrawTriangle(Center(transform), RU(transform), RD(transform));
		DrawTriangle(Center(transform), LD(transform), LU(transform));
	}
	else
	{
		DrawTriangle(Center(transform), LU(transform), RU(transform));
		DrawTriangle(Center(transform), LD(transform), RD(transform));
	}
}

void Piece_X::Update()
{
	//
}
