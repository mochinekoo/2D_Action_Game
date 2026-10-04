#pragma once
#include "Vector2D.h"
class Matrix2D {
public:
	float mat00, mat01, tx;
	float mat10, mat11, ty;
	//0 0 1

	Matrix2D(float m00, float m01, float tx,
		float m10, float m11, float ty) :
		mat00(m00), mat01(m01), tx(tx),
		mat10(m10), mat11(m11), ty(ty) {
	}

	static Matrix2D Identity();
	static Matrix2D Translation(Vector2D vec);
	static Matrix2D Scaling(Vector2D vec);
	static Matrix2D Rotation(float angle);
	static Matrix2D Multiply(Matrix2D a, Matrix2D b);
	static Vector2D Transform(Matrix2D mat, Vector2D vec);
};

