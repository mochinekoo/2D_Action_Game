#include "SceneManager.h"
#include "BootScene.h"

SceneManager::SceneManager() {
	sceneList.push_back(new BootScene());

	ChangeScene("BootScene");
}

SceneManager::~SceneManager() {
}

int SceneManager::ChangeScene(std::string name) {
	for (auto scene : sceneList) {
		if (scene->GetName()._Equal(name)) {
			currentScene = scene;
			return 0;
		}
	}

	return -1;
}

SceneBase* SceneManager::GetCurrentScene() {
	return currentScene;
}

