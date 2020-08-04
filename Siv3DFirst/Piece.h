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
	void DrawBG(std::shared_ptr<Transform> transform);
	void DrawTriangle(Vec2 v1, Vec2 v2, Vec2 v3);
	Vec2 Center(std::shared_ptr<Transform> transform);
	Vec2 RU(std::shared_ptr<Transform> transform);
	Vec2 RD(std::shared_ptr<Transform> transform);
	Vec2 LU(std::shared_ptr<Transform> transform);
	Vec2 LD(std::shared_ptr<Transform> transform);
};

