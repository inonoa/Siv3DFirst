#pragma once
#include "Piece.h"
#include "Enums.h"
class Piece_L :
    public Piece
{
public:
    Piece_L(TFPtr transform);
    void Update();
    void Draw(std::shared_ptr<class Transform> transform);
    bool CanJoint(enum Direction direction);
};
