#pragma once
#include "PieceType.h"
#include "Enums.h"
class Piece_L :
    public PieceType
{
public:
    Piece_L();
    void Draw();
    bool CanJoint(enum Direction direction);
};
