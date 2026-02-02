#pragma once
#include "SceneBase.h"
#include "Player.h"
#include <vector>

class RunningScene : public SceneBase {
private:
	int timer;
	int backgroundHandle;
	Player* player;
public:
	std::vector<DrawBase*> drawObj;
	RunningScene();
	void Init() override;
	void Update() override;
	void Draw() override;
};

