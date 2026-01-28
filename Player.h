#pragma once
#include "DrawBase.h"
class Player : public DrawBase {
public:
	Player(Location2D location, Vector2D vector);
	void Init() override;
	void Update() override;
	void Draw() override;

	bool IsOnGround();
private:
	int imageHandle;
};

