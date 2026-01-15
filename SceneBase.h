#pragma once
#include <string>

class SceneBase {
private:
	std::string name_;
	SceneBase();
public:
	SceneBase(std::string name);

	virtual void Init() = 0;
	virtual void Update() = 0;
	virtual void Draw() = 0;

	std::string GetName();
};

