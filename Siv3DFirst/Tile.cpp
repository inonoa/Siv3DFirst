#include "Tile.h"

Tile::Tile(Transform* parent, Vec2 localPos)
{
	Transform tf(parent, localPos);
	this->transform = &tf;
	this->filled = RandomBool();
}

void Tile::Update()
{
	//
}

void Tile::Draw()
{
	Vec2 pos = transform->WorldPos();
	Rect(pos.x, pos.y, 48, 48)
		.draw(
			filled ? 
			ColorF(0.2f, 0.8f, 0.3f) : 
			ColorF(0.95f, 0.95f, 0.95f)
		);
}
