#pragma once
#include "Piece.h"
class Piece_M :
    public Piece
{
    void Update();
    void Draw(TFPtr transform);
    bool CanJoint(enum Direction direction);
};

