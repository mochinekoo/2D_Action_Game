#pragma once
#include "DrawBase.h"
class Player : public DrawBase {
public:
	static inline Location2D scrollLocation_;
	Player(Location2D location, Vector2D vector);
	void Init() override;
	void Update() override;
	void Draw() override;
private:
	int imageHandle;
	int imageWidth, imageHeight;
};

