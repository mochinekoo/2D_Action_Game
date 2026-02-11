#include "RunningScene.h"
#include "SceneBase.h"
#include <DxLib.h>
#include "Stage.h"
#include "Player.h"
#include "GameUtil.h"
#include "framework.h"

RunningScene::RunningScene() 
 : SceneBase("RunningScene") {
	timer = 0;
	backgroundHandle = LoadGraph("background_1.png");
	stage = new Stage();
	drawObj.push_back(stage);
	
	for (int y = 0; y < stage->GetMapHeight(); y++) {
		for (int x = 0; x < stage->GetMapWidth(); x++) {
			int tile = stage->GetMapData(x, y);
			if (tile == 5) {
				player = new Player(Location2D(x * 64, y * 64), Vector2D(4, 5));
				player->Init();
			}
		}
	}
}

void RunningScene::Init() {
}

void RunningScene::Update() {
	timer++;
	player->Update();

	for (DrawBase* draw : drawObj) {
		draw->Update();
	}
}

void RunningScene::Draw() {
	DrawGraph(0, 0, backgroundHandle, false); //背景
	player->Draw();

	for (DrawBase* draw : drawObj) {
		draw->Draw();
	}

	//文字
	TextUtil::DrawFix2DText(DrawType::RIGHT, GameScreen::WIDTH - 1, 0, 30, (std::string)"残りのハート：" + std::to_string(player->GetHeart()), GetColor(255, 255, 255), GetColor(0, 0, 0));
}
