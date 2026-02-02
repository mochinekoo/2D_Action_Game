#include "Bullet.h"
#include "DrawBase.h"
#include "MapManager.h"
#include <DxLib.h>
#include "Player.h"
#include "framework.h"
#include "SceneManager.h"
#include "RunningScene.h"

namespace {
	MapManager& mapManager = MapManager::GetInstance();
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
	location_.x_ += vector_.x_;
	int upRightCol = GetRightCollision(location_.x_ + BULLET_RADIUS, location_.y_ - BULLET_RADIUS);
	int downRightCol = GetRightCollision(location_.x_ + BULLET_RADIUS, location_.y_ + BULLET_RADIUS);
	int maxRightCol = max(upRightCol, downRightCol);
	location_.x_ -= maxRightCol;

	if (0 > location_.x_ || location_.x_ > GameScreen::WIDTH) {
		RunningScene* running = (RunningScene*)sceneManager.GetCurrentScene();
		for (auto in = running->drawObj.begin(); in != running->drawObj.end(); in++) {
			if (*in == this) {
				running->drawObj.erase(in);
				break;
			}
		}
		delete this;
	}
}

void Bullet::Draw() {
	DrawCircle(location_.x_ - Player::scrollLocation_.x_, location_.y_, BULLET_RADIUS, BULLET_COLOR);
}

int Bullet::GetUpCollision(int x, int y)
{
	if (IsBlockCollision(x, y)) {
		int dy = y % 64;
		return 64 - dy;
	}
	return 0;
}

int Bullet::GetDownCollision(int x, int y)
{
	if (IsBlockCollision(x, y)) {
		int dy = y % 64;
		return dy + 1;
	}
	return 0;
}

int Bullet::GetLeftCollision(int x, int y)
{
	if (IsBlockCollision(x, y)) {
		int dx = x % 64;
		return 64 - dx;
	}
	return 0;
}

int Bullet::GetRightCollision(int x, int y)
{
	if (IsBlockCollision(x, y)) {
		int dx = x % 64;
		return dx + 1;
	}
	return 0;
}

bool Bullet::IsBlockCollision(int x, int y)
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
