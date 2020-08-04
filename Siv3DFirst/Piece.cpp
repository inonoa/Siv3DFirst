#include "Piece.h"

ColorF Piece::WHITE(0.95, 0.95, 0.95, 1);
ColorF Piece::GREEN(0.1, 0.8, 0.3, 1);

void Piece::Rotate(bool clockwise)
{
	switch (this->direction)
	{
	case Direction::RIGHT:
		this->direction = clockwise ? DOWN : UP;
		break;
	case Direction::DOWN:
		this->direction = clockwise ? LEFT : RIGHT;
		break;
	case Direction::LEFT:
		this->direction = clockwise ? UP : DOWN;
		break;
	case Direction::UP:
		this->direction = clockwise ? RIGHT : LEFT;
		break;
	}
}
