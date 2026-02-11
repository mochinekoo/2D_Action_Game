#pragma once
#include <cmath>
#include "Vector2D.h"

namespace MathUtilty {

	const float PI = 3.1415926535f;

	namespace EaseFunction {

		inline float easeInSine(float x) {
			return 1 - cos((x * PI) / 2);
		}

		inline float easeOutSine(float x) {
			return sin((x * PI) / 2);
		}

		inline float GetLerp(int start, int end, float rate, float (*easeFunc)(float x) = nullptr) {
			if (rate < 0.0f) rate = 0.0f;
			if (rate > 1.0f) rate = 1.0f;
			if (easeFunc != nullptr) {
				rate = easeFunc(rate);
			}
			return (end - start) * rate + start;
		}
	}
}