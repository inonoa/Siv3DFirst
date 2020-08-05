#pragma once
#include "Piece.h"
class Piece_Q :
    public Piece
{
public:
    void Update();
    void Draw(TFPtr transform);
    bool CanJoint(enum Direction direction);
};

