#include "Piece_L.h"

void Piece_L::Update()
{

}

void Piece_L::Draw(std::shared_ptr<Transform> transform)
{
	DrawBG(transform);
	DrawTriangle(LU(transform), RD(transform), LD(transform));
}
