#include "Bullet.h"
#include "DrawBase.h"
#include <DxLib.h>
#include "Player.h"
#include "framework.h"
#include "SceneManager.h"
#include "RunningScene.h"
#include <vector>
#include "Stage.h"

namespace {
	SceneManager& sceneManager = SceneManager::GetInstance();
	const int BULLET_RADIUS = 5;
	const unsigned int BULLET_COLOR = GetColor(255, 0, 0);
}

Bullet::Bullet(Location2D location, Vector2D vector)
	: DrawBase("Bullet", location, vector) {
}

Bullet::~Bullet() {
}

void Bullet::Init() {
}

void Bullet::Update() {
	RunningScene* runningScene = (RunningScene*)sceneManager.GetScene("RunningScene");
	Stage* stage = runningScene->stage;
	location_.x_ += vector_.x_;
	int upRightCol = stage->GetRightCollision(location_.x_ + BULLET_RADIUS, location_.y_ - BULLET_RADIUS);
	int downRightCol = stage->GetRightCollision(location_.x_ + BULLET_RADIUS, location_.y_ + BULLET_RADIUS);
	int maxRightCol = max(upRightCol, downRightCol);
	location_.x_ -= maxRightCol;

	if (0 > location_.x_ || location_.x_ > GameScreen::WIDTH) {
		for (auto in = runningScene->drawObj.begin(); in != runningScene->drawObj.end(); in++) {
			if (*in == this) {
				runningScene->drawObj.erase(in);
				break;
			}
		}
		delete this;
	}
}

void Bullet::Draw() {
	DrawCircle(location_.x_ - Player::scrollLocation_.x_, location_.y_, BULLET_RADIUS, BULLET_COLOR);
}