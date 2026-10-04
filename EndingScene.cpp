#include "EndingScene.h"
#include "MochinekoEngine/SceneBase.h"
#include <DxLib.h>
#include "MochinekoEngine/SceneManager.h"
#include "MochinekoEngine/GameUtil.h"
#include "MochinekoEngine/framework.h"

namespace {
	SceneManager& sceneManager = SceneManager::GetInstance();
}

EndingScene::EndingScene()
	: SceneBase("EndingScene") {
	backgroundHandle = LoadGraph("background_1.png");
}

void EndingScene::Init() {
}

void EndingScene::Update() {
	count++;
}

void EndingScene::Draw() {
	DrawGraph(0, 0, backgroundHandle, false); //”wŒi
	TextUtil::DrawFix2DText(DrawType::CENTER, GameScreen::WIDTH / 2, GameScreen::HEIGHT / 2, 30, "ƒQ[ƒ€ƒI[ƒo[!", GetColor(255, 255, 255), GetColor(0, 0, 0));

	if (count >= 100) {
		sceneManager.ChangeScene("WaitingScene");
	}
}
