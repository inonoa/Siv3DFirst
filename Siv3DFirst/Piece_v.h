#pragma once
#include "Piece.h"
class Piece_v :
    public Piece
{
public:
    Piece_v(TFPtr transform);
    void Update();
    void Draw();
    bool CanJoint(enum Direction direction);
};

