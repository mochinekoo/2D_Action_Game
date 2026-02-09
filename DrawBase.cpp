#include "DrawBase.h"
#include "SceneManager.h"
#include "RunningScene.h"

DrawBase::DrawBase(std::string name, Location2D location, Vector2D vector) {
	name_ = name;
	location_ = location;
	vector_ = vector;
}

DrawBase::DrawBase(std::string name, Location2D location, Vector2D vector, Collider collider)
	: DrawBase(name, location, vector){
	collider_ = collider;
}

DrawBase::DrawBase(std::string name, Location2D location, Vector2D vector, unsigned int color)
	: DrawBase(name, location, vector) { 
	color_ = color;
}

std::string DrawBase::GetName()
{
	return name_;
}

Location2D DrawBase::GetLocation() {
	return location_;
}

void DrawBase::SetLocation(Location2D location) {
	location_ = location;
}

Vector2D DrawBase::GetVector() {
	return vector_;
}

void DrawBase::SetVector(Vector2D vector) {
	vector_ = vector;
}

void DrawBase::UpdateBlockCollision(BorderType type) {
	SceneManager& sceneManager = SceneManager::GetInstance();
	RunningScene* runningScene = (RunningScene*)sceneManager.GetScene("RunningScene");
	Stage* stage = runningScene->stage;

	//左上を基準にしているため
	int rightBorder = collider_.left_ + collider_.right_;
	int bottomBorder = collider_.top_ + collider_.bottom_;

	//各判定
	if (type == BorderType::LEFT) {
		int upLeftCol = stage->GetLeftCollision(location_.x_, location_.y_); //左上
		int downLeftCol = stage->GetLeftCollision(location_.x_, location_.y_ + bottomBorder); //左下
		int maxLeftCol = std::max(upLeftCol, downLeftCol);
		location_.x_ += maxLeftCol;
	}
	else if (type == BorderType::RIGHT) {
		int upRightCol = stage->GetRightCollision(location_.x_ + rightBorder, location_.y_); //右上
		int downRightCol = stage->GetRightCollision(location_.x_ + rightBorder, location_.y_ + bottomBorder); //右下
		int maxRightCol = std::max(upRightCol, downRightCol);
		location_.x_ -= maxRightCol;
	}
	else if (type == BorderType::TOP) {
		int upLeftCol = stage->GetUpCollision(location_.x_, location_.y_ ); //左上
		int upRightCol = stage->GetUpCollision(location_.x_ + rightBorder, location_.y_); //右上
		int maxUpCol = std::max(upLeftCol, upRightCol);
		if (maxUpCol > 0) {
			location_.y_ += maxUpCol;
			vector_.y_ = 0;
		}
	}
	else if (type == BorderType::BOTTOM) {
		int downLeftCol = stage->GetDownCollision(location_.x_, location_.y_ + bottomBorder);
		int downRightCol = stage->GetDownCollision(location_.x_ + rightBorder, location_.y_ + bottomBorder);
		int maxDownCol = std::max(downLeftCol, downRightCol);
		if (maxDownCol > 0) {
			location_.y_ -= maxDownCol;
			vector_.y_ = 0;
		}
	}
}

unsigned int DrawBase::GetDrawColor() {
	return color_;
}

void DrawBase::SetDrawColor(unsigned int color) {
	color_ = color;
}

std::string DrawBase::GetCustomName() {
	return customName_;
}

void DrawBase::SetCustomName(std::string name) {
	customName_ = name;
}

int DrawBase::GetCustomData() {
	return customData_;
}

void DrawBase::SetCustomData(int data) {
	customData_ = data;
}