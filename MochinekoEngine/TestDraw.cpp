#include "TestDraw.h"
#include "DrawBase.h"
#include "Location2D.h"
#include "Vector2D.h"
#include <DxLib.h>
#include "framework.h"

namespace {
	const int CIRCLE_RADIUS = 10;
}

TestDraw::TestDraw() 
	: DrawBase("TestDraw", Location2D(0, 0), Vector2D(3, 0), GetColor(255, 255, 255)) {
}

void TestDraw::Init() {
	location_ = Location2D(0, 0);
	vector_ = Vector2D(0, 0);
}

void TestDraw::Update() {
	count++;
	location_.x_ += vector_.x_;
	location_.y_ += vector_.y_;

	if (0 >= location_.x_ || 1280 <= location_.x_) {
		vector_.x_ *= -1;
	}
	if (0 >= location_.y_ || 720 <= location_.y_) {
		vector_.y_ *= -1;
	}
	
}

void TestDraw::Draw() {
	DrawCircle(location_.x_, location_.y_, CIRCLE_RADIUS, color_, true);
}


