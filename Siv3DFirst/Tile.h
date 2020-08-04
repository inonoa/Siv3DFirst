#pragma once
#include "Transform.h"
#include <memory>

class Tile
{
public:
	Tile(std::shared_ptr<Transform> parent, Vec2 localPos);
	void Update();
	void Draw();

private:
	std::shared_ptr<Transform> transform;
	bool filled;
};

