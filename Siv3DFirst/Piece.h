#pragma once

#include "Enums.h"
#include "Transform.h"
#include <Siv3D.hpp>
#include "PieceType.h"

class PieceType;

using TFPtr = std::shared_ptr<Transform>;
using TypePtr = std::shared_ptr<PieceType>;

class Piece
{
public:
	Piece(TFPtr transform, TypePtr type_, int line_x);
	void Draw();
	void Update();
	bool CanJoint(enum Direction direction);
	void Rotate(bool clockwise);
	static ColorF WHITE;
	static ColorF GREEN;
	void Fall();
	TFPtr GetTF();
	void DrawBG();
	void DrawTriangle(Vec2 v1, Vec2 v2, Vec2 v3);
	Vec2 Center();
	Vec2 RU();
	Vec2 RD();
	Vec2 LU();
	Vec2 LD();
	Direction Direction();
	double GetAngleRad();
	bool IsFalling();
	bool IsOnTile();
	Vector2D<int> PosOnBoard();
	void Land(int x, int y);
	void LoseGround();
	static double width;
	static double green_width;

private:
	double angle_rad;
	TFPtr transform;
	TypePtr type;
	enum State { Falling, OnTile };
	State state;
	Vector2D<int> pos_on_board;
};

