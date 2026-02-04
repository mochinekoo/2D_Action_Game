#pragma once
#include <string>
#include <vector>
#include "DrawBase.h"

class SceneBase {
private:
	std::string name_;
	SceneBase();	
public:
	std::vector<DrawBase*> drawObj;
	SceneBase(std::string name);

	virtual void Init() = 0;
	virtual void Update() = 0;
	virtual void Draw() = 0;

	std::string GetName();
};

