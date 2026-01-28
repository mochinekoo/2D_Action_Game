#include "Player.h"
#include <DxLib.h>
#include "DrawBase.h"
#include "MapManager.h"
#include "GameUtil.h"
#include "framework.h"

namespace {
	const float GRAVITY = 1.0f;
	const int JUMP_POWER = 15;
}

Player::Player(Location2D location, Vector2D vector)
 : DrawBase("Player", location, vector) {
	imageHandle = LoadGraph("player.png");
}

void Player::Init() {
}

void Player::Update() {
	int worldX = location_.x_ / 64;
	int worldY = location_.y_ / 64;

	if (CheckHitKey(KEY_INPUT_LEFT)) {
		location_.x_ -= vector_.x_;
	}
	if (CheckHitKey(KEY_INPUT_RIGHT)) {
		location_.x_ += vector_.x_;
	}
	if (KeyInput::isKeyFixDown(KEY_INPUT_SPACE)) {
		if (IsOnGround()) {
			vector_.y_ = JUMP_POWER;
		}
	}

	location_.y_ -= vector_.y_;
	vector_.y_ -= GRAVITY;
	if (IsOnGround()) {
		vector_.y_ = 0;
	}

	bool inXArea = (0 < worldX && worldX < GameScreen::WIDTH / 64) && (0 < location_.x_ && location_.x_ < GameScreen::WIDTH);
	bool inYArea = (0 < worldY && worldY < GameScreen::HEIGHT / 64) && (0 < location_.y_ && location_.y_ < GameScreen::HEIGHT);
	if (inXArea && inYArea) {}
	else {
		location_.x_ = 64 * 2;
		location_.y_ = 64 * 2;
	}
}

void Player::Draw() {
	DrawGraph(location_.x_, location_.y_, imageHandle, false);
}

bool Player::IsOnGround(){
	MapManager& mapManager = MapManager::GetInstance();
	Location2D underLoc = Location2D(location_.x_, location_.y_ + 64);
	float underWorldX = underLoc.x_ / 64;
	float underWorldY = underLoc.y_ / 64;
	if (mapManager.GetMapData()[((int)underWorldY)+1][(int)underWorldX] == 1) {
		return true;
	}
	return false;
}
