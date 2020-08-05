#include "Tile.h"
#include "Piece.h"
#include "Piece_v.h"
#include "Piece_L.h"
#include "Piece_X.h"
#include "Piece_M.h"
#include "Piece_Q.h"
#include <memory>

Tile::Tile(std::shared_ptr<Transform> parent, Vec2 localPos)
{
	this->transform = MakeShared<Transform>(parent, localPos);

	RandomGenerate();
}

void Tile::RandomGenerate()
{
	int rd = Random<int>(0, 5);
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
	case 4:
		this->piece = MakeShared<Piece_M>();
		break;
	case 5:
		this->piece = MakeShared<Piece_Q>();
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
		Vec2 lu = pos + Vec2(-24, -24);
		Vec2 ld = pos + Vec2(-24, 24);
		Vec2 ru = pos + Vec2(24, -24);
		Vec2 rd = pos + Vec2(24, 24);
		if (piece->CanJoint(RIGHT)) Line(ru, rd).draw(ColorF(1, 0, 0.5, 1));
		if (piece->CanJoint(UP)) Line(ru, lu).draw(ColorF(1, 0, 0.5, 1));
		if (piece->CanJoint(DOWN)) Line(rd, ld).draw(ColorF(1, 0, 0.5, 1));
		if (piece->CanJoint(LEFT)) Line(lu, ld).draw(ColorF(1, 0, 0.5, 1));
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
