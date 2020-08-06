#pragma once
#include <Siv3D.hpp>
#include "Transform.h"
#include "Piece.h"

class Piece;

using PiecePtr = std::shared_ptr<Piece>;

class PieceType
{
public:
	PieceType();
	void SetPiece(PiecePtr piece);
	virtual void Draw() = 0;
	virtual bool CanJoint(Direction direction) = 0;
protected:
	PiecePtr piece;
};
