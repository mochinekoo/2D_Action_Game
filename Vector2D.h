#pragma once

//ベクトルの2次元のクラス。扱いやすいように、全てpublic。
class Vector2D {
public:
	float x_;
	float y_;

	Vector2D();
	Vector2D(float x, float y);

	float GetX();
	void SetX(float x);
	float GetY();
	void SetY(float y);

	float Length();

	Vector2D Add(float x, float y);
	Vector2D Subtract(float x, float y);
	Vector2D Multiply(float scalar);
	Vector2D Normalize();

	float Angle();
	float Dot(Vector2D& otherVec);
	float Cross(Vector2D& otherVec);
	
	static Vector2D FromAngle(float angle);	
};
