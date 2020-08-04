#pragma once
#include "Piece.h"
class Piece_X :
    public Piece
{
public:
    void Update();
    void Draw(TFPtr transform);
};

