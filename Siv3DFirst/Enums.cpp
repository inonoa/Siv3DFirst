#include "Enums.h"

Direction Direction_rotated(enum Direction direction, enum Direction rotate)
{
	switch (direction)
	{
	case RIGHT:
		switch (rotate)
		{
		case RIGHT: return RIGHT; break;
		case UP:    return UP;    break;
		case LEFT:  return LEFT;  break;
		case DOWN:  return DOWN;  break;
		}
		break;
	case UP:
		switch (rotate)
		{
		case RIGHT: return UP;    break;
		case UP:    return LEFT;  break;
		case LEFT:  return DOWN;  break;
		case DOWN:  return RIGHT; break;
		}
		break;
	case LEFT:
		switch (rotate)
		{
		case RIGHT: return LEFT;  break;
		case UP:    return DOWN;  break;
		case LEFT:  return RIGHT; break;
		case DOWN:  return UP;    break;
		}
		break;
	case DOWN:
		switch (rotate)
		{
		case RIGHT: return DOWN;  break;
		case UP:    return RIGHT; break;
		case LEFT:  return UP;    break;
		case DOWN:  return LEFT;  break;
		}
		break;
	}
}
