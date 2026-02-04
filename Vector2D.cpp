#include "Vector2D.h"
#include <cmath>

Vector2D::Vector2D() {
	x_ = 0;
	y_ = 0;
}

Vector2D::Vector2D(float x, float y) {
	x_ = x;
	y_ = y;
}

float Vector2D::GetX() {
	return x_;
}

void Vector2D::SetX(float x) {
	x_ = x;
}

float Vector2D::GetY() {
	return y_;
}

void Vector2D::SetY(float y) {
	y_ = y;
}

float Vector2D::Length() {
	return sqrt(x_*x_ + y_*y_);
}

Vector2D Vector2D::Add(float x, float y) {
	float newX = x_ + x;
	float newY = y_ + y;
	return Vector2D(newX, newY);
}

Vector2D Vector2D::Subtract(float x, float y) {
	float newX = x_ - x;
	float newY = y_ - y;
	return Vector2D(newX, newY);
}

Vector2D Vector2D::Multiply(float scalar) {
	float newX = x_ * scalar;
	float newY = y_ * scalar;
	return Vector2D(newX, newY);
}

Vector2D Vector2D::Normalize() {
	float newX = (Length() == 0 ? 0 : x_ / Length());
	float newY = (Length() == 0 ? 0 : y_ / Length());;
	return Vector2D(newX, newY);
}

/// <summary>
/// ベクトルの向きをラジアンで返す関数
/// </summary>
/// <returns></returns>
float Vector2D::Angle()
{
	return std::atan2(y_, x_);
}

/// <summary>
/// 内積をする関数
/// </summary>
/// <param name="otherVec">内積したいベクトル</param>
/// <returns></returns>
float Vector2D::Dot(Vector2D& otherVec)
{
	return x_ * otherVec.x_ + y_ * otherVec.y_;
}

/// <summary>
/// 外積をする関数
/// </summary>
/// <param name="otherVec">外積したいベクトル</param>
/// <returns></returns>
float Vector2D::Cross(Vector2D& otherVec)
{
	return x_ * otherVec.y_ - y_ * otherVec.x_;
}

/// <summary>
/// ラジアンから単位ベクトルを作る関数
/// </summary>
/// <param name="angle"></param>
/// <returns></returns>
Vector2D Vector2D::FromAngle(float angle) {
	return Vector2D(std::cos(angle), std::sin(angle));
}
