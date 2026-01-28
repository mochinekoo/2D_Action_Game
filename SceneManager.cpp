#include "SceneManager.h"
#include "BootScene.h"
#include "WaitingScene.h"
#include "RunningScene.h"

SceneManager::SceneManager() {}

SceneManager::~SceneManager() {
}

int SceneManager::ChangeScene(std::string name) {
	SceneBase* scene = GetScene(name);
	if (scene != nullptr) {
		currentScene = scene;
		currentScene->Init();
		return 0;
	}

	return -1;
}

SceneBase* SceneManager::GetCurrentScene() {
	return currentScene;
}

SceneBase* SceneManager::GetScene(std::string name) {
	for (auto scene : sceneList) {
		if (scene->GetName()._Equal(name)) {
			return scene;
		}
	}
	return nullptr;
}

bool SceneManager::IsCurrentScene(std::string name) {
	if (currentScene == nullptr) {
		return false;
	}
	return currentScene->GetName()._Equal(name);
}

void SceneManager::InitScenes() {
	sceneList.push_back(new BootScene());
	sceneList.push_back(new WaitingScene());
	sceneList.push_back(new RunningScene());

	ChangeScene("BootScene");
	ChangeScene("WaitingScene");
}

