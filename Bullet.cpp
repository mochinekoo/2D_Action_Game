#include "Bullet.h"
#include "DrawBase.h"
#include <DxLib.h>
#include "Player.h"
#include "framework.h"
#include "SceneManager.h"
#include "RunningScene.h"
#include <vector>
#include "Stage.h"
#include <cmath>

namespace {
	SceneManager& sceneManager = SceneManager::GetInstance();
	const int BULLET_RADIUS = 10;
	const unsigned int BULLET_COLOR = GetColor(255, 0, 0);
}

Bullet::Bullet(Location2D location, Vector2D vector)
	: DrawBase("Bullet", location, vector) {
	angle_ = 0.0f;
}

Bullet::~Bullet() {
}

void Bullet::Init() {
}

void Bullet::Update() {
	RunningScene* runningScene = (RunningScene*)sceneManager.GetScene("RunningScene");
	Stage* stage = runningScene->stage;
	location_.x_ += (vector_.x_);
	location_.y_ += (vector_.y_ * sin(angle_));
	angle_+=0.1f;

	int upRightCol = stage->GetRightCollision(1, location_.x_ + BULLET_RADIUS, location_.y_ - BULLET_RADIUS);
	int downRightCol = stage->GetRightCollision(1, location_.x_ + BULLET_RADIUS, location_.y_ + BULLET_RADIUS);
	int maxRightCol = max(upRightCol, downRightCol);
	location_.x_ -= maxRightCol;

	bool inScreen = 0 < location_.x_ && location_.x_ < GameScreen::WIDTH;

	if (!inScreen || maxRightCol > 0) {
		runningScene->RemoveDrawObject(this);
	}
}

void Bullet::Draw() {
	DrawCircle(location_.x_ - Player::scrollLocation_.x_, location_.y_, BULLET_RADIUS, BULLET_COLOR);
}