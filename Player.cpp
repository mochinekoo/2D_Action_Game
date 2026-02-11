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
	const int DEFAULT_HEART = 5;
	SceneManager& sceneManager = SceneManager::GetInstance();
}

Player::Player(Location2D location, Vector2D vector)
 : DrawBase("Player", location, vector) {
	imageHandle = LoadGraph("player.png");
	GetGraphSize(imageHandle, &imageWidth, &imageHeight);
	scrollLocation_ = { 0, 0 };
	collider_ = Collider((imageHeight / 2), (imageHeight / 2), (imageWidth / 2) - 1, (imageWidth / 2) - 1);
	heart_ = DEFAULT_HEART;
}

void Player::Init() {
}

void Player::Update() {
	RunningScene* runningScene = (RunningScene*)sceneManager.GetScene("RunningScene");
	Stage* stage = runningScene->stage;

	if (CheckHitKey(KEY_INPUT_LEFT)) {
		location_.x_ -= vector_.x_;
		UpdateBlockCollision(BorderType::LEFT);
	}
	if (CheckHitKey(KEY_INPUT_RIGHT)) {
		location_.x_ += vector_.x_;
		UpdateBlockCollision(BorderType::RIGHT);
	}
	if (KeyInput::isKeyFixDown(KEY_INPUT_SPACE)) {
		vector_.y_ = JUMP_POWER;
	}
	if (KeyInput::isKeyFixDown(KEY_INPUT_P)) {
		RunningScene* runningScene = (RunningScene*) sceneManager.GetCurrentScene();
		runningScene->drawObj.push_back(new Bullet(location_, { 3, 3 }));
	}

	location_.y_ -= vector_.y_;
	vector_.y_ -= GRAVITY;

	UpdateBlockCollision(BorderType::TOP);
	UpdateBlockCollision(BorderType::BOTTOM);

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
		SetHeart(GetHeart() - 1); //マイナスにならないように、関数を通す
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
		stage->GetUpCollision(1, location_.x_, location_.y_),
		stage->GetUpCollision(1, location_.x_ + imageWidth, location_.y_),
		vector_.y_);
}

int Player::GetHeart() {
	return heart_;
}

void Player::SetHeart(int heart) {
	if (heart <= 0) heart = 0;
	heart_ = heart;
}


