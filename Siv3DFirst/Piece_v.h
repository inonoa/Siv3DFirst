#pragma once
#include "PieceType.h"
class Piece_v :
    public PieceType
{
public:
    Piece_v();
    void Draw();
    bool CanJoint(enum Direction direction);
};

