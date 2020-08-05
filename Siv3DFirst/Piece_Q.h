#pragma once
#include "Piece.h"
class Piece_Q :
    public Piece
{
public:
    Piece_Q(TFPtr transform);
    void Update();
    void Draw();
    bool CanJoint(enum Direction direction);
};

