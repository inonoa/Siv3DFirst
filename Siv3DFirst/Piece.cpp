#include "Piece.h"
#include <math.h>

ColorF Piece::WHITE(0.95, 0.95, 0.95, 1);
ColorF Piece::GREEN(0.1, 0.8, 0.3, 1);

Piece::Piece(TFPtr transform, TypePtr type, int line_x)
{
	angle_rad = Random<int>(0, 3) * 0.5_pi;
	this->transform = transform;
	this->type = type;
	this->state = State::Falling;
	this->pos_on_board = Vector2D<int>(line_x, -1);
}

void Piece::Rotate(bool clockwise)
{
	switch (this->Direction())
	{
	case Direction::RIGHT:
		this->angle_rad = clockwise ? 1.5_pi : 0.5_pi;
		break;
	case Direction::DOWN:
		this->angle_rad = clockwise ? 1_pi : 0;
		break;
	case Direction::LEFT:
		this->angle_rad = clockwise ? 0.5_pi : 1.5_pi;
		break;
	case Direction::UP:
		this->angle_rad = clockwise ? 0 : 1_pi;
		break;
	}
}

void Piece::Fall()
{
	double deltatime = Scene::DeltaTime();
	double speed = width * 2;
	transform->MovePos(0, deltatime * speed);
}

TFPtr Piece::GetTF()
{
	return transform;
}

bool Piece::CanJoint(enum Direction direction)
{
	return type->CanJoint(direction);
}

void Piece::Draw()
{
	type->Draw();
}

void Piece::Update()
{
	if (IsFalling()) Fall();
}

void Piece::DrawTriangle(Vec2 v1, Vec2 v2, Vec2 v3)
{
	Triangle(v1.x, v1.y, v2.x, v2.y, v3.x, v3.y).draw(Piece::GREEN);
}

void Piece::DrawBG()
{
	Vec2 pos = transform->WorldPos();
	Rect(pos.x - green_width / 2.0, pos.y - green_width / 2.0, green_width, green_width)
		.rotatedAt(transform->WorldPos(), -angle_rad)
		.draw(Piece::WHITE);
}

Vec2 Piece::Center()
{
	return transform->WorldPos();
}

Vec2 Piece::RU()
{
	return transform->WorldPos() + Vec2(green_width / 2.0, -green_width / 2.0).rotated(-angle_rad);
}
Vec2 Piece::RD()
{
	return transform->WorldPos() + Vec2(green_width / 2.0, green_width / 2.0).rotated(-angle_rad);
}
Vec2 Piece::LU()
{
	return transform->WorldPos() + Vec2(-green_width / 2.0, -green_width / 2.0).rotated(-angle_rad);
}
Vec2 Piece::LD()
{
	return transform->WorldPos() + Vec2(-green_width / 2.0, green_width / 2.0).rotated(-angle_rad);
}

Direction Piece::Direction()
{
	if ((angle_rad < 0.25_pi) || (angle_rad > 1.75_pi)) return Direction::RIGHT;
	if (angle_rad < 0.75_pi) return Direction::UP;
	if (angle_rad < 1.25_pi) return Direction::LEFT;
	return Direction::DOWN;
}

double Piece::GetAngleRad()
{
	return angle_rad;
}

bool Piece::IsFalling()
{
	return state == State::Falling;
}

bool Piece::IsOnTile()
{
	return state == State::OnTile;
}

Vector2D<int> Piece::PosOnBoard()
{
	return pos_on_board;
}

void Piece::Land(int x, int y)
{
	pos_on_board = Vector2D<int>(x, y);
	state = State::OnTile;
}

void Piece::LoseGround()
{
	state = State::Falling;
}

double Piece::width = 50;
double Piece::green_width = 48;
