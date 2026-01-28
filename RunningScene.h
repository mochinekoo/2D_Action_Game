#pragma once
#include "SceneBase.h"
#include "Player.h"

class RunningScene : public SceneBase {
private:
	int timer;
	int backgroundHandle;
	Player* player;
public:
	RunningScene();
	void Init() override;
	void Update() override;
	void Draw() override;
};

