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