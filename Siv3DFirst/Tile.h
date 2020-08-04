#pragma once
#include "Transform.h"

class Tile
{
public:
	Tile(Transform* parent, Vec2 localPos);
	void Update();
	void Draw();

private:
	Transform* transform;
	bool filled;
};

