#include "RunningScene.h"
#include "SceneBase.h"
#include <DxLib.h>
#include "MapManager.h"
#include "Player.h"

namespace {
	MapManager& mapManager = MapManager::GetInstance();
}

RunningScene::RunningScene() 
 : SceneBase("RunningScene") {
	timer = 0;
	backgroundHandle = LoadGraph("background_1.png");
	
	for (int y = 0; y < mapManager.GetMapData().size(); y++) {
		for (int x = 0; x < mapManager.GetMapData()[0].size(); x++) {
			int tile = mapManager.GetMapData()[y].at(x);
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
}

void RunningScene::Draw() {
	DrawGraph(0, 0, backgroundHandle, false); //”wŒi
	player->Draw();

	for (int y = 0; y < mapManager.GetMapData().size(); y++) {
		for (int x = 0; x < mapManager.GetMapData()[0].size(); x++) {
			int tile = mapManager.GetMapData()[y].at(x);
			if (tile == 1) {
				DrawBox((x * 64) - Player::scrollLocation_.x_, y * 64, (x * 64 + 64) - Player::scrollLocation_.x_, y * 64 + 64, GetColor(0, 0, 0), true); //’n–Ê
			}
		}
	}
}
