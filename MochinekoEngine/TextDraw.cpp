#include "TextDraw.h"
#include <DxLib.h>
#include <string>
#include "DrawBase.h"

TextDraw::TextDraw(std::string name, Location2D location, Vector2D vector, std::string text, int size, unsigned int textColor) 
  : TextDraw(name, location, vector, text, size, textColor, -1){
}

TextDraw::TextDraw(std::string name, Location2D location, Vector2D vector, std::string text, int size, unsigned int textColor, unsigned int edgeColor)
 : DrawBase(name, location, vector){
	text_ = text;
	textColor_ = textColor;
	edgeColor_ = edgeColor;
	size_ = size;
}

void TextDraw::Init() {
}

void TextDraw::Update() {
}

void TextDraw::Draw() {
	TextUtil::DrawFix2DText(drawType_, location_.x_, location_.y_, size_, text_, textColor_, edgeColor_);
}
