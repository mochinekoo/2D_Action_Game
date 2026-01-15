#include "BootScene.h"
#include "TestDraw.h"

namespace {
	TestDraw* testDraw = new TestDraw();
}

BootScene::BootScene()
  : SceneBase("BootScene") {
	count = 0;
}

void BootScene::Init() {
	count = 0;
	testDraw->Init();
}

void BootScene::Update() {
	count++;
	testDraw->Update();
}

void BootScene::Draw() {
	testDraw->Draw();
}
