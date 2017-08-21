#pragma once

#include "Matrix.h"

class Box {
public:
	Box();

private:
//	Mat3x3 _coord;
	Vec3 _center;
	Vec3 _extent;
	Vec3 _scale;
};