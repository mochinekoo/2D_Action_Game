#pragma once
#include "DrawBase.h"
class Player : public DrawBase {
public:
	Player(Location2D location, Vector2D vector);
	void Init() override;
	void Update() override;
	void Draw() override;

	int GetDownCollision(int x, int y);
	int GetUpCollision(int x, int y);
	int GetLeftCollision(int x, int y);
	int GetRightCollision(int x, int y);
	bool IsBlockCollision(int x, int y);
private:
	int imageHandle;
	int imageWidth, imageHeight;
};

