#include "RunningScene.h"
#include "SceneBase.h"
#include <DxLib.h>
#include "MapManager.h"

namespace {
	MapManager& mapManager = MapManager::GetInstance();
}

RunningScene::RunningScene() 
 : SceneBase("RunningScene") {
	timer = 0;
	backgroundHandle = LoadGraph("background_1.png");
}

void RunningScene::Init() {
}

void RunningScene::Update()
{
}

void RunningScene::Draw() {
	DrawGraph(0, 0, backgroundHandle, false); //îwåi

	for (int y = 0; y < mapManager.GetMapData().size(); y++) {
		for (int x = 0; x < mapManager.GetMapData()[0].size(); x++) {
			int tile = mapManager.GetMapData()[y].at(x);
			if (tile == 1) {
				DrawBox(x * 64, y * 64, x * 64 + 64, y * 64 + 64, GetColor(0, 0, 0), true); //ínñ 
			}
		}
	}
}
