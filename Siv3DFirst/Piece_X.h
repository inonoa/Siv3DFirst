#pragma once
#include "Piece.h"
class Piece_X :
    public Piece
{
public:
    Piece_X(TFPtr transform);
    void Update();
    void Draw();
    bool CanJoint(enum Direction direction);
};

