#pragma once
#include "Piece.h"
class Piece_v :
    public Piece
{
public:
    Piece_v(TFPtr transform);
    void Update();
    void Draw(std::shared_ptr<class Transform> transform);
    bool CanJoint(enum Direction direction);
};

