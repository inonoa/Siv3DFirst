#include "Piece_v.h"

void Piece_v::Update()
{
	//
}

void Piece_v::Draw(std::shared_ptr<Transform> transform)
{
	Vec2 pos = transform->WorldPos();
	Rect(pos.x + 1, pos.y + 1, 48, 48).draw(Piece::WHITE);
	Triangle tri;
	Vec2 center = pos + Vec2(25, 25);
	Vec2 ru = pos + Vec2(49, 1);
	Vec2 rd = pos + Vec2(49, 49);
	Vec2 ld = pos + Vec2(1, 49);
	Vec2 lu = pos + Vec2(1, 1);
	switch (direction)
	{
	case Direction::RIGHT:
		tri = Triangle(center.x, center.y, ru.x, ru.y, rd.x, rd.y);
		break;
	case Direction::UP:
		tri = Triangle(center.x, center.y, lu.x, lu.y, ru.x, ru.y);
		break;
	case Direction::LEFT:
		tri = Triangle(center.x, center.y, ld.x, ld.y, lu.x, lu.y);
		break;
	case Direction::DOWN:
		tri = Triangle(center.x, center.y, rd.x, rd.y, ld.x, ld.y);
		break;
	default:
		break;
	}
	tri.draw(Piece::GREEN);
}
