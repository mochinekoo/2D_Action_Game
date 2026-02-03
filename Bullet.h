#pragma once
#include "DrawBase.h"
class Bullet : public DrawBase {
private:
	float angle_;
public:
	Bullet(Location2D location, Vector2D vector);
	~Bullet();
	void Init() override;
	void Update() override;
	void Draw() override;
};

