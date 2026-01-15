#pragma once
#include "SceneBase.h"

//Å‰‚ÌƒV[ƒ“B
class BootScene : public SceneBase {
private:
	int count;
public:
	BootScene();

	void Init() override;
	void Update() override;
	void Draw() override;
};

