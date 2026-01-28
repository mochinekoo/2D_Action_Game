#include "WaitingScene.h"
#include <DxLib.h>
#include "SceneBase.h"
#include "GameUtil.h"
#include "framework.h"
#include "SceneManager.h"

WaitingScene::WaitingScene()
 : SceneBase("WaitingScene") {
	counter = 0;
	backgroundHandle = LoadGraph("background_1.png");
}

void WaitingScene::Init() {
	counter = 0;
	backgroundHandle = LoadGraph("background_1.png");
}

void WaitingScene::Update() {
	counter++;

	if (KeyInput::isKeyFixDown(KEY_INPUT_SPACE)) {
		SceneManager::GetInstance().ChangeScene("RunningScene");
	}
}

void WaitingScene::Draw() {
	DrawGraph(0, 0, backgroundHandle, false);
	TextUtil::DrawFix2DText(DrawType::CENTER,
		GameScreen::WIDTH / 2, GameScreen::HEIGHT / 2 - 30*1, 30,
		"2Dアクションゲーム", GetColor(255, 255, 255), GetColor(0, 0, 0));
	TextUtil::DrawFix2DText(DrawType::CENTER, 
		GameScreen::WIDTH / 2, GameScreen::HEIGHT / 2, 30,
		"ゲームを開始するには「Space」を押してください", GetColor(255, 255, 255), GetColor(0, 0, 0));
}
