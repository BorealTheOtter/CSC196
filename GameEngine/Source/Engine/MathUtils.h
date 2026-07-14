#pragma once

namespace sr::math
{
	constexpr float PI = 3.1415926535897932384626433832795f;
	constexpr float TWO_PI = 6.283185307179586476925286766559f;
	constexpr float HALF_PI = 1.5707963267948966192313216916398f;

	template <typename T>
	T Wrap(T value, T min, T max) {

		return (value < min) ? max : (value > max) ? min : value;
		
	}

	template<typename T>
	T Min(T a, T b) {
		return (a < b) ? a : b;
	}

	template <typename T>
	T Max(T a, T b) {
		return (a > b) ? a : b;
	}

	template <typename T>
	T Clamp(T value, T min, T max) {
		return (value < min) ? min : (value > max) ? max : value;
	}

}