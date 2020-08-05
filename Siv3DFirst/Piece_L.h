#pragma once
#include "Piece.h"
#include "Enums.h"
class Piece_L :
    public Piece
{
public:
    void Update();
    void Draw(std::shared_ptr<Transform> transform);
    bool CanJoint(enum Direction direction);
};
