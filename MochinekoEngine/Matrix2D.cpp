#include "Matrix2D.h"
#include <cmath>

//単位行列
Matrix2D Matrix2D::Identity() {
	return Matrix2D(1, 0, 0,
		0, 1, 0);
}

//平行移動行列
Matrix2D Matrix2D::Translation(Vector2D vec) {
	return Matrix2D(1, 0, vec.GetX(),
		0, 1, vec.GetY());
}

//拡大縮小行列
Matrix2D Matrix2D::Scaling(Vector2D vec) {
	return Matrix2D(vec.GetX(), 0, 0,
		0, vec.GetY(), 0);
}

//回転行列
Matrix2D Matrix2D::Rotation(float angle) {
	float cos = std::cos(angle);
	float sin = std::sin(angle);
	return Matrix2D(cos, -sin, 0,
		sin, cos, 0);
}

//行列どうしの合成
Matrix2D Matrix2D::Multiply(Matrix2D a, Matrix2D b) {
	return Matrix2D(
		a.mat00 * b.mat00 + a.mat01 * b.mat10,
		a.mat00 * b.mat01 + a.mat01 * b.mat11,
		a.mat00 * b.tx + a.mat01 * b.ty + a.tx,

		a.mat10 * b.mat00 + a.mat11 * b.mat10,
		a.mat10 * b.mat01 + a.mat11 * b.mat11,
		a.mat10 * b.tx + a.mat11 * b.ty + a.ty
	);
}

//行列とベクトルの乗算
Vector2D Matrix2D::Transform(Matrix2D mat, Vector2D vec) {
	return Vector2D(
		mat.mat00 * vec.GetX() + mat.mat01 * vec.GetY() + mat.tx,
		mat.mat10 * vec.GetX() + mat.mat11 * vec.GetY() + mat.ty);
}