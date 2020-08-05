#include "Tile.h"
#include "Piece.h"
#include "Piece_v.h"
#include "Piece_L.h"
#include "Piece_X.h"
#include <memory>

Tile::Tile(std::shared_ptr<Transform> parent, Vec2 localPos)
{
	this->transform = MakeShared<Transform>(parent, localPos);
	int rd = Random<int>(0, 3);
	switch (rd)
	{
	case 0:
		break;
	case 1:
		this->piece = MakeShared<Piece_v>();
		break;
	case 2:
		this->piece = MakeShared<Piece_L>();
		break;
	case 3:
		this->piece = MakeShared<Piece_X>();
		break;
	}
}

void Tile::Update()
{
	//
}

void Tile::Draw()
{
	Vec2 pos = transform->WorldPos();
	if (piece)
	{
		piece->Draw(transform);
	}
	else
	{
		Rect(pos.x - 24, pos.y - 24, 48, 48)
			.draw(ColorF(0.75f, 0.75f, 0.95f));
	}
}

std::shared_ptr<Piece> Tile::GetPiece()
{
	return piece;
}

std::shared_ptr<Transform> Tile::GetTransform()
{
	return this->transform;
}
