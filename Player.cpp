#include "Player.h"
#include <DxLib.h>
#include "DrawBase.h"
#include "MapManager.h"
#include "GameUtil.h"
#include "framework.h"

namespace {
	const float GRAVITY = 1.0f;
	const int JUMP_POWER = 15;
	MapManager& mapManager = MapManager::GetInstance();
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
	if (CheckHitKey(KEY_INPUT_LEFT)) {
		location_.x_ -= vector_.x_;
		int upLeftCol = GetLeftCollision(location_.x_, location_.y_);
		int downLeftCol = GetLeftCollision(location_.x_, location_.y_ + imageHeight);
		int maxLeftCol = max(upLeftCol, downLeftCol);
		location_.x_ += maxLeftCol;
	}
	if (CheckHitKey(KEY_INPUT_RIGHT)) {
		location_.x_ += vector_.x_;
		int upRightCol = GetRightCollision(location_.x_ + imageWidth, location_.y_);
		int downRightCol = GetRightCollision(location_.x_ + imageWidth, location_.y_ + imageHeight);
		int maxRightCol = max(upRightCol, downRightCol);
		location_.x_ -= maxRightCol;
	}
	if (KeyInput::isKeyFixDown(KEY_INPUT_SPACE)) {
		vector_.y_ = JUMP_POWER;
	}

	location_.y_ -= vector_.y_;
	vector_.y_ -= GRAVITY;

	int upLeftCol = GetUpCollision(location_.x_, location_.y_);
	int upRightCol = GetUpCollision(location_.x_ + imageWidth, location_.y_);
	int maxUpCol = max(upLeftCol, upRightCol);
	if (maxUpCol > 0) {
		location_.y_ += maxUpCol; 
		vector_.y_ = 0;
	}

	int downLeftCol = GetDownCollision(location_.x_, location_.y_ + imageHeight);
	int downRightCol = GetDownCollision(location_.x_ + imageWidth, location_.y_ + imageHeight);
	int maxDownCol = max(downLeftCol, downRightCol);
	if (maxDownCol > 0) {
		location_.y_ -= maxDownCol;
		vector_.y_ = 0;
	}

	int worldX = location_.x_ / 64;
	int worldY = location_.y_ / 64;
	bool inXArea = (0 <= worldX && worldX < mapManager.GetMapData()[0].size());
	bool inYArea = (0 <= worldY && worldY < mapManager.GetMapData().size());
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
	DrawGraph(location_.x_ - scrollLocation_.x_, location_.y_, imageHandle, false);
	DrawFormatString(0, 0, GetColor(255, 255, 255), "Down: %d, %d, %0.3f", 
		GetUpCollision(location_.x_, location_.y_),
		GetUpCollision(location_.x_ + imageWidth, location_.y_),
		vector_.y_);
}

int Player::GetUpCollision(int x, int y)
{
	if (IsBlockCollision(x, y)) {
		int dy = y % 64;
		return 64 - dy;
	}
	return 0;
}

int Player::GetDownCollision(int x, int y)
{
	if (IsBlockCollision(x, y)) {
		int dy = y % 64;
		return dy + 1;
	}
	return 0;
}

int Player::GetLeftCollision(int x, int y)
{
	if (IsBlockCollision(x, y)) {
		int dx = x % 64;
		return 64 - dx;
	}
	return 0;
}

int Player::GetRightCollision(int x, int y)
{
	if (IsBlockCollision(x, y)) {
		int dx = x % 64;
		return dx + 1;
	}
	return 0;
}

bool Player::IsBlockCollision(int x, int y)
{
	int mapWidth = mapManager.GetMapData()[0].size();
	int mapHeight = mapManager.GetMapData().size();
	int worldX = x / 64;
	int worldY = y / 64;
	if (0 <= worldX && worldX < mapWidth &&
		0 <= worldY && worldY < mapHeight) {
		if (mapManager.GetMapData()[worldY][worldX] == 1) {
			return true;
		}
	}
	return false;
}


