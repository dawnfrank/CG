#pragma once

#include "mymath.h"

class Box {
public:
	Box();

	Vec3 GetCenter() { return _center; }

private:
//	Mat3 _coord;
	Vec3 _center;
	Vec3 _extent;
	Vec3 _scale;
};