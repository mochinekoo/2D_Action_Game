#pragma once
#include <string>
#include "Location2D.h"
#include "Vector2D.h"

struct Collider {
	float top_;
	float bottom_;
	float left_;
	float right_;

	Collider() {
		top_ = 0;
		bottom_ = 0;
		left_ = 0;
		right_ = 0;
	}

	Collider(float top, float bottom, float left, float right) {
		top_ = top;
		bottom_ = bottom;
		left_ = left;
		right_ = right;
	}
};

enum BorderType {
	TOP,
	BOTTOM,
	LEFT,
	RIGHT
};

class DrawBase {
protected:
	//基本情報
	std::string name_;
	Location2D location_;
	Vector2D vector_;
	Collider collider_;

	//追加用
	unsigned int color_;

	//その他
	std::string customName_;
	int customData_;
public:
	DrawBase(std::string name, Location2D location, Vector2D vector);
	DrawBase(std::string name, Location2D location, Vector2D vector, Collider collider);
	DrawBase(std::string name, Location2D location, Vector2D vector, unsigned int color);

	virtual void Init() = 0;
	virtual void Update() = 0;
	virtual void Draw() = 0;

	//オブジェクトの基本情報
	std::string GetName();
	Location2D GetLocation();
	void SetLocation(Location2D location);
	Vector2D GetVector();
	void SetVector(Vector2D vector);

	//追加情報
	unsigned int GetDrawColor();
	void SetDrawColor(unsigned int color);
	
	//その他
	std::string GetCustomName();
	void SetCustomName(std::string name);
	int GetCustomData();
	void SetCustomData(int data);
};