#pragma once
#include "DrawBase.h"
class Bullet : public DrawBase {
public:
	Bullet(Location2D location, Vector2D vector);
	~Bullet();
	void Init() override;
	void Update() override;
	void Draw() override;
	int GetUpCollision(int x, int y);
	int GetDownCollision(int x, int y);
	int GetLeftCollision(int x, int y);
	int GetRightCollision(int x, int y);
	bool IsBlockCollision(int x, int y);
};

