#pragma once

enum Direction {
	RIGHT = 0, UP = 1, LEFT = 2, DOWN = 3
};

Direction Direction_rotated(Direction direction, Direction rotate);

Direction Opposite(Direction direction);
