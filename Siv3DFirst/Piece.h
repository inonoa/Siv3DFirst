#pragma once

#include "Enums.h"
#include "Transform.h"
#include <Siv3D.hpp>

using TFPtr = std::shared_ptr<Transform>;

class Piece
{
public:
	Piece(TFPtr transform);
	virtual void Draw() = 0;
	virtual void Update() = 0;
	virtual bool CanJoint(Direction direction) = 0;
	void Rotate(bool clockwise);
	static ColorF WHITE;
	static ColorF GREEN;
	void Fall();
	TFPtr GetTF();

protected:
	void DrawBG();
	void DrawTriangle(Vec2 v1, Vec2 v2, Vec2 v3);
	Vec2 Center();
	Vec2 RU();
	Vec2 RD();
	Vec2 LU();
	Vec2 LD();
	double angle_rad;
	Direction Direction();
	TFPtr transform;
};

