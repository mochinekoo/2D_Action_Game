#pragma once
#include "SceneBase.h"
#include "Player.h"
#include <vector>
#include "DrawBase.h"
#include "Stage.h"

class RunningScene : public SceneBase {
private:
	int timer;
	int backgroundHandle;
	Player* player;
public:
	Stage* stage;
	RunningScene();
	void Init() override;
	void Update() override;
	void Draw() override;
};

