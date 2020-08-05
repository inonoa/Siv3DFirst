#pragma once
#include "Piece.h"
class Piece_v :
    public Piece
{
public:
    void Update();
    void Draw(std::shared_ptr<Transform> transform);
    bool CanJoint(enum Direction direction);
};

