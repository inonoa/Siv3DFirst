#pragma once

#include <Siv3D.hpp>

class Transform
{
public:
	Transform(std::shared_ptr<Transform> parent, Vec2 localPos);
	Transform(Vec2 localPos);
	Vec2 WorldPos();
	void MovePos(double dx, double dy);
	void SetLocalPos(double x, double y);
	void SetWorldPos(double x, double y);
	Vec2 LocalPos();

private:
	std::shared_ptr<Transform> parent;
	Vec2 localPos;
};

