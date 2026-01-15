#include "BootScene.h"

BootScene::BootScene()
  : SceneBase("BootScene") {
	count = 0;
}

void BootScene::Init() {
	count = 0;
}

void BootScene::Update() {
	count++;
}

void BootScene::Draw() {
}
