#pragma once
#include "Piece.h"
class Piece_L :
    public Piece
{
public:
    void Update();
    void Draw(std::shared_ptr<Transform> transform);
};

