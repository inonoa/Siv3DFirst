#include "Tile.h"

Tile::Tile(std::shared_ptr<Transform> parent, Vec2 localPos)
{
	this->transform = MakeShared<Transform>(parent, localPos);
	this->filled = RandomBool();
}

void Tile::Update()
{
	//
}

void Tile::Draw()
{
	Vec2 pos = transform->WorldPos();
	Rect(pos.x + 1, pos.y + 1, 48, 48)
		.draw(
			filled ? 
			ColorF(0.2f, 0.8f, 0.3f) : 
			ColorF(0.95f, 0.95f, 0.95f)
		);
}
