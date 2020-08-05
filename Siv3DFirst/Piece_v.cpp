#include "Piece_v.h"

void Piece_v::Update()
{
	//
}

void Piece_v::Draw(std::shared_ptr<Transform> transform)
{
	DrawBG(transform);
	DrawTriangle(Center(transform), LU(transform), RU(transform));
}
