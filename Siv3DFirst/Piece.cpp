#include "Piece.h"

ColorF Piece::WHITE(0.95, 0.95, 0.95, 1);
ColorF Piece::GREEN(0.1, 0.8, 0.3, 1);

void Piece::Rotate(bool clockwise)
{
	switch (this->direction)
	{
	case Direction::RIGHT:
		this->direction = clockwise ? DOWN : UP;
		break;
	case Direction::DOWN:
		this->direction = clockwise ? LEFT : RIGHT;
		break;
	case Direction::LEFT:
		this->direction = clockwise ? UP : DOWN;
		break;
	case Direction::UP:
		this->direction = clockwise ? RIGHT : LEFT;
		break;
	}
}

void Piece::DrawTriangle(Vec2 v1, Vec2 v2, Vec2 v3)
{
	Triangle(v1.x, v1.y, v2.x, v2.y, v3.x, v3.y).draw(Piece::GREEN);
}

void Piece::DrawBG(TFPtr transform)
{
	Vec2 pos = transform->WorldPos();
	Rect(pos.x + 1, pos.y + 1, 48, 48).draw(Piece::WHITE);
}

Vec2 Piece::Center(TFPtr transform)
{
	return transform->WorldPos() + Vec2(25, 25);
}

Vec2 Piece::RU(TFPtr transform)
{
	return transform->WorldPos() + Vec2(49, 1);
}
Vec2 Piece::RD(TFPtr transform)
{
	return transform->WorldPos() + Vec2(49, 49);
}
Vec2 Piece::LU(TFPtr transform)
{
	return transform->WorldPos() + Vec2(1, 1);
}
Vec2 Piece::LD(TFPtr transform)
{
	return transform->WorldPos() + Vec2(1, 49);
}
