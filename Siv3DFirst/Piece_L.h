#pragma once
#include "Piece.h"
#include "Enums.h"
class Piece_L :
    public Piece
{
public:
    Piece_L(TFPtr transform);
    void Update();
    void Draw();
    bool CanJoint(enum Direction direction);
};
