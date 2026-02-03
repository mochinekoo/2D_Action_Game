#include "Player.h"
#include <DxLib.h>
#include "DrawBase.h"
#include "GameUtil.h"
#include "framework.h"
#include "Bullet.h"
#include "SceneManager.h"
#include "RunningScene.h"
#include "Stage.h"

namespace {
	const float GRAVITY = 1.0f;
	const int JUMP_POWER = 15;
	SceneManager& sceneManager = SceneManager::GetInstance();
}

Player::Player(Location2D location, Vector2D vector)
 : DrawBase("Player", location, vector) {
	imageHandle = LoadGraph("player.png");
	GetGraphSize(imageHandle, &imageWidth, &imageHeight);
	scrollLocation_ = { 0, 0 };
}

void Player::Init() {
}

void Player::Update() {
	RunningScene* runningScene = (RunningScene*)sceneManager.GetScene("RunningScene");
	Stage* stage = runningScene->stage;

	if (CheckHitKey(KEY_INPUT_LEFT)) {
		location_.x_ -= vector_.x_;
		int upLeftCol = stage->GetLeftCollision(location_.x_, location_.y_);
		int downLeftCol = stage->GetLeftCollision(location_.x_, location_.y_ + imageHeight);
		int maxLeftCol = max(upLeftCol, downLeftCol);
		location_.x_ += maxLeftCol;
	}
	if (CheckHitKey(KEY_INPUT_RIGHT)) {
		location_.x_ += vector_.x_;
		int upRightCol = stage->GetRightCollision(location_.x_ + imageWidth, location_.y_);
		int downRightCol = stage->GetRightCollision(location_.x_ + imageWidth, location_.y_ + imageHeight);
		int maxRightCol = max(upRightCol, downRightCol);
		location_.x_ -= maxRightCol;
	}
	if (KeyInput::isKeyFixDown(KEY_INPUT_SPACE)) {
		vector_.y_ = JUMP_POWER;
	}
	if (KeyInput::isKeyFixDown(KEY_INPUT_P)) {
		RunningScene* runningScene = (RunningScene*) sceneManager.GetCurrentScene();
		runningScene->drawObj.push_back(new Bullet(location_, { 3, 0 }));
	}

	location_.y_ -= vector_.y_;
	vector_.y_ -= GRAVITY;

	int upLeftCol = stage->GetUpCollision(location_.x_, location_.y_);
	int upRightCol = stage->GetUpCollision(location_.x_ + imageWidth, location_.y_);
	int maxUpCol = max(upLeftCol, upRightCol);
	if (maxUpCol > 0) {
		location_.y_ += maxUpCol; 
		vector_.y_ = 0;
	}

	int downLeftCol = stage->GetDownCollision(location_.x_, location_.y_ + imageHeight);
	int downRightCol = stage->GetDownCollision(location_.x_ + imageWidth, location_.y_ + imageHeight);
	int maxDownCol = max(downLeftCol, downRightCol);
	if (maxDownCol > 0) {
		location_.y_ -= maxDownCol;
		vector_.y_ = 0;
	}

	int worldX = location_.x_ / 64;
	int worldY = location_.y_ / 64;
	bool inXArea = (0 <= worldX && worldX < stage->GetMapWidth());
	bool inYArea = (0 <= worldY && worldY < stage->GetMapHeight());
	if (inXArea && inYArea) {}
	else {
		location_.x_ = 64*2;
		location_.y_ = 64*2;
		vector_.y_ = 0;
		scrollLocation_ = { 0, 0 };
	}

	int scrollSize = GameScreen::WIDTH / 2;
	int scrollResultX = location_.x_ - scrollLocation_.x_;
	if (location_.x_ < scrollSize) {
		scrollLocation_.x_ = 0;
	}
	else {
		if (scrollResultX > scrollSize) {
			scrollLocation_.x_ = location_.x_ - scrollSize;
		}
		if (scrollResultX < scrollSize) {
			scrollLocation_.x_ = location_.x_ - scrollSize;
		}
	}
}

void Player::Draw() {
	RunningScene* runningScene = (RunningScene*)sceneManager.GetScene("RunningScene");
	Stage* stage = runningScene->stage;

	DrawGraph(location_.x_ - scrollLocation_.x_, location_.y_, imageHandle, false);
	DrawFormatString(0, 0, GetColor(255, 255, 255), "Down: %d, %d, %0.3f", 
		stage->GetUpCollision(location_.x_, location_.y_),
		stage->GetUpCollision(location_.x_ + imageWidth, location_.y_),
		vector_.y_);
}


