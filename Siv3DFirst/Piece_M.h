#pragma once
#include "Piece.h"
class Piece_M :
    public Piece
{
public:
    Piece_M(TFPtr transform);
    void Update();
    void Draw();
    bool CanJoint(enum Direction direction);
};

