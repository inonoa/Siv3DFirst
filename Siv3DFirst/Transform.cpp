#include "Transform.h"

Transform::Transform(Vec2 localPos)
{
	this->localPos = localPos;
}

Transform::Transform(std::shared_ptr<Transform> parent, Vec2 localPos)
{
	this->parent = parent;
	this->localPos = localPos;
}

Vec2 Transform::WorldPos()
{
	if (parent != nullptr)
	{
		return parent->WorldPos() + localPos;
	}
	else
	{
		return localPos;
	}
}

void Transform::MovePos(double dx, double dy)
{
	localPos += Vec2(dx, dy);
}

void Transform::SetLocalPos(double x, double y)
{
	localPos = Vec2(x, y);
}

void Transform::SetWorldPos(double x, double y)
{
	if (parent)
	{
		localPos = Vec2(x, y) - parent->WorldPos();
	}
	else
	{
		localPos = Vec2(x, y);
	}
}

Vec2 Transform::LocalPos()
{
	return localPos;
}
