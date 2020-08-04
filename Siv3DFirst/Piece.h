#pragma once

#include "Enums.h"
#include "Transform.h"
#include <Siv3D.hpp>

using TFPtr = std::shared_ptr<Transform>;

class Piece
{
public:
	virtual void Draw(TFPtr transform) = 0;
	virtual void Update() = 0;
	void Rotate(bool clockwise);
	static ColorF WHITE;
	static ColorF GREEN;
protected:
	Direction direction;
	void DrawBG(TFPtr transform);
	void DrawTriangle(Vec2 v1, Vec2 v2, Vec2 v3);
	Vec2 Center(TFPtr transform);
	Vec2 RU(TFPtr transform);
	Vec2 RD(TFPtr transform);
	Vec2 LU(TFPtr transform);
	Vec2 LD(TFPtr transform);
};

