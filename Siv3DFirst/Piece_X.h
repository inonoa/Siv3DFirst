#pragma once
#include "PieceType.h"
class Piece_X :
    public PieceType
{
public:
    Piece_X();
    void Draw();
    bool CanJoint(enum Direction direction);
};

