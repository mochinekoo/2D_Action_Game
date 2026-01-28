#pragma once
#include "SceneBase.h"
class RunningScene : public SceneBase {
private:
	int timer;
	int backgroundHandle;
public:
	RunningScene();
	void Init() override;
	void Update() override;
	void Draw() override;
};

