#pragma once
#include "DrawBase.h"

//sample—p‚Ì•`‰æ•¨B
class TestDraw : public DrawBase {
private:
	int count;
public:
	TestDraw();

	void Init() override;
	void Update() override;
	void Draw() override;
};

