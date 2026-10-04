#pragma once
#include "DrawBase.h"
#include <string>
#include "GameUtil.h"

class TextDraw : public DrawBase {
private:
	std::string text_;
	DrawType drawType_;
	unsigned int textColor_;
	unsigned int edgeColor_;
	int size_;
public:
	TextDraw(std::string name, Location2D location, Vector2D vector, std::string text, int size, unsigned int color);
	TextDraw(std::string name, Location2D location, Vector2D vector, std::string text, int size, unsigned int textColor, unsigned int edgeColor);
	void Init() override;
	void Update() override;
	void Draw() override;
};

