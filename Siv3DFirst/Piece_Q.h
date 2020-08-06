#pragma once
#include "PieceType.h"
class Piece_Q :
    public PieceType
{
public:
    Piece_Q();
    void Draw();
    bool CanJoint(enum Direction direction);
};

