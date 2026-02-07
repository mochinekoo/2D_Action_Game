#include "SceneBase.h"

SceneBase::SceneBase(std::string name) {
	name_ = name;
}

void SceneBase::AddDrawObject(DrawBase* obj) {
	drawObj.push_back(obj);
}

void SceneBase::RemoveDrawObject(DrawBase* obj) {
	for (auto in = drawObj.begin(); in != drawObj.end(); in++) {
		if (*in == obj) {
			drawObj.erase(in);
			delete obj;
			break;
		}
	}
}

DrawBase* SceneBase::GetDrawObject(std::string objName) {
	for (DrawBase* obj : drawObj) {
		if (obj->GetName()._Equal(objName)) {
			return obj;
		}
	}
	return nullptr;
}

std::string SceneBase::GetName() {
	return name_;
}
