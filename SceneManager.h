#pragma once
#include <vector>
#include "SceneBase.h"

class SceneManager {
private:
	SceneBase* currentScene;
	std::vector<SceneBase*> sceneList;
	
	SceneManager();
	~SceneManager();
public:
	inline static SceneManager& GetInstance() {
		static SceneManager sceneManager;
		return sceneManager;
	}

	int ChangeScene(std::string name);
	SceneBase* GetCurrentScene();
	SceneBase* GetScene(std::string name);
	bool IsCurrentScene(std::string name);
	void InitScenes();
};

