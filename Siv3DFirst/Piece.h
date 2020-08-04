#pragma once

#include "Enums.h"
#include "Transform.h"
#include <Siv3D.hpp>

class Piece
{
public:
	virtual void Draw(std::shared_ptr<Transform> transform) = 0;
	virtual void Update() = 0;
	void Rotate(bool clockwise);
	static ColorF WHITE;
	static ColorF GREEN;
protected:
	Direction direction;
};

