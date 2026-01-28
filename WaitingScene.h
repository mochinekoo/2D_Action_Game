#pragma once
#include "SceneBase.h"
class WaitingScene : public SceneBase {
private:
	int counter;
	int backgroundHandle;
public:
	WaitingScene();
	void Init() override;
	void Update() override;
	void Draw() override;
};

