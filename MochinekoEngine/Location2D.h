#pragma once

//場所の2D専用のクラス。扱いやすいように、全てpublic。
class Location2D {
public:
	float x_;
	float y_;

	Location2D();
	Location2D(float x, float y);

	float GetX();
	void SetX(float x);
	float GetY();
	void SetY(float y);

	Location2D Add(float x, float y);
	Location2D Subtract(float x, float y);
	Location2D Multiply(float x, float y);

	float Distance(Location2D location);

};

