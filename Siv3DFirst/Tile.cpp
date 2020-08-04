#include "Tile.h"
#include "Piece.h"
#include "Piece_v.h"
#include <memory>

Tile::Tile(std::shared_ptr<Transform> parent, Vec2 localPos)
{
	this->transform = MakeShared<Transform>(parent, localPos);
	this->piece = RandomBool() ? MakeShared<Piece_v>() : nullptr;
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
		Rect(pos.x + 1, pos.y + 1, 48, 48)
			.draw(ColorF(0.75f, 0.75f, 0.95f));
	}
}

std::shared_ptr<Piece> Tile::GetPiece()
{
	return piece;
}
