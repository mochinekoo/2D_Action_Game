#include "Stage.h"
#include "DrawBase.h"
#include <DxLib.h>
#include "Player.h"

Stage::Stage()
	: DrawBase("Stage", Location2D{0, 0}, Vector2D{0, 0}) {
}

Stage::~Stage() {
}

void Stage::Draw() {
	for (int y = 0; y < GetMapHeight(); y++) {
		for (int x = 0; x < GetMapWidth(); x++) {
			int tile = mapData[y].at(x);
			if (tile == 1) {
				DrawBox(
					(x * 64) - Player::scrollLocation_.x_,
					y * 64, 
					(x * 64 + 64) - Player::scrollLocation_.x_,
					y * 64 + 64, 
					GetColor(0, 0, 0), true
				); //地面
			}
			else if (tile == 2) {
				DrawBox(
					(x * 64) - Player::scrollLocation_.x_,
					y * 64,
					(x * 64 + 64) - Player::scrollLocation_.x_,
					y * 64 + 64,
					GetColor(255, 0, 0), true
				); //ブロック
			}
		}
	}
}

void Stage::Update() {
}

void Stage::Init() {
}

int Stage::GetMapData(int x, int y) {
	if (0 <= x && GetMapWidth() - 1 >= x &&
		0 <= y && GetMapHeight() - 1 >= y)  {
		return mapData[y][x];
	}
	return -1;
}

void Stage::SetMapData(int x, int y, int data) {
	if (0 <= x && GetMapWidth() - 1 >= x &&
		0 <= y && GetMapHeight() - 1 >= y) {
		mapData[y][x] = data;
	}
}

int Stage::GetMapWidth() {
	return mapData[0].size();
}

int Stage::GetMapHeight() {
	return mapData.size();
}

int Stage::GetUpCollision(int blockID, int x, int y) {
	if (IsBlockCollision(blockID, x, y)) {
		int dy = y % 64;
		return 64 - dy;
	}
	return 0;
}

int Stage::GetDownCollision(int blockID, int x, int y) {
	if (IsBlockCollision(blockID, x, y)) {
		int dy = y % 64;
		return dy + 1;
	}
	return 0;
}

int Stage::GetLeftCollision(int blockID, int x, int y) {
	if (IsBlockCollision(blockID, x, y)) {
		int dx = x % 64;
		return 64 - dx;
	}
	return 0;
}

int Stage::GetRightCollision(int blockID, int x, int y) {
	if (IsBlockCollision(blockID, x, y)) {
		int dx = x % 64;
		return dx + 1;
	}
	return 0;
}

bool Stage::IsBlockCollision(int blockID, int x, int y) {
	int mapWidth = mapData[0].size();
	int mapHeight = mapData.size();
	int worldX = x / 64;
	int worldY = y / 64;
	if (0 <= worldX && worldX < mapWidth &&
		0 <= worldY && worldY < mapHeight) {
		if (mapData[worldY][worldX] == blockID) {
			return true;
		}
	}
	return false;
}



