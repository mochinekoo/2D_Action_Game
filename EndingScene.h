#pragma once
#include "SceneBase.h"
class EndingScene : public SceneBase {
private:
	int count;
	int backgroundHandle;
public:
	EndingScene();

	void Init() override;
	void Update() override;
	void Draw() override;
};

