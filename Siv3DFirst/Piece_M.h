#pragma once
#include "PieceType.h"
class Piece_M :
    public PieceType
{
public:
    Piece_M();
    void Draw();
    bool CanJoint(enum Direction direction);
};

