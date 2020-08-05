#include "Piece.h"

ColorF Piece::WHITE(0.95, 0.95, 0.95, 1);
ColorF Piece::GREEN(0.1, 0.8, 0.3, 1);

Piece::Piece()
{
	angle_rad = 0;
}

void Piece::Rotate(bool clockwise)
{
	switch (this->Direction())
	{
	case Direction::RIGHT:
		this->angle_rad = clockwise ? 1.5_pi : 0.5_pi;
		break;
	case Direction::DOWN:
		this->angle_rad = clockwise ? 1_pi : 0;
		break;
	case Direction::LEFT:
		this->angle_rad = clockwise ? 0.5_pi : 1.5_pi;
		break;
	case Direction::UP:
		this->angle_rad = clockwise ? 0 : 1_pi;
		break;
	}
	Print << angle_rad;
	Print << Direction();
}

void Piece::DrawTriangle(Vec2 v1, Vec2 v2, Vec2 v3)
{
	Triangle(v1.x, v1.y, v2.x, v2.y, v3.x, v3.y).draw(Piece::GREEN);
}

void Piece::DrawBG(TFPtr transform)
{
	Vec2 pos = transform->WorldPos();
	Rect(pos.x - 24, pos.y - 24, 48, 48).draw(Piece::WHITE);
}

Vec2 Piece::Center(TFPtr transform)
{
	return transform->WorldPos();
}

Vec2 Piece::RU(TFPtr transform)
{
	return transform->WorldPos() + Vec2(24, -24).rotated(-angle_rad);
}
Vec2 Piece::RD(TFPtr transform)
{
	return transform->WorldPos() + Vec2(24, 24).rotated(-angle_rad);
}
Vec2 Piece::LU(TFPtr transform)
{
	return transform->WorldPos() + Vec2(-24, -24).rotated(-angle_rad);
}
Vec2 Piece::LD(TFPtr transform)
{
	return transform->WorldPos() + Vec2(-24, 24).rotated(-angle_rad);
}

Direction Piece::Direction()
{
	if ((angle_rad < 0.25_pi) || (angle_rad > 1.75_pi)) return Direction::RIGHT;
	if (angle_rad < 0.75_pi) return Direction::UP;
	if (angle_rad < 1.25_pi) return Direction::LEFT;
	return Direction::DOWN;
}
