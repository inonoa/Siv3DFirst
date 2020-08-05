#include "Piece_X.h"

void Piece_X::Draw(TFPtr transform)
{
	DrawBG(transform);
	DrawTriangle(Center(transform), RU(transform), RD(transform));
	DrawTriangle(Center(transform), LD(transform), LU(transform));
}

void Piece_X::Update()
{
	//
}
