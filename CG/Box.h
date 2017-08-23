#pragma once

#include <vector>

#include "mymath.h"

class Box {
public:
	Box();

	Vec3 GetCenter() { return _center; }
	std::vector<Vec3> GetVertex() {
		_vertexs.clear();
		int sx, sy, sz;
		for (int i = 0; i != 8; ++i) {
			sx = i >> 2 & 1 ? 1 : -1;
			sy = i >> 1 & 1 ? 1 : -1;
			sz = i & 1 ? 1 : -1;
			_vertexs.push_back(Vec3(sx*_extent[0]+_center[0], sy*_extent[1] + _center[1], sz*_extent[2] + _center[2]));
		}
		return _vertexs;
	}

private:
//	Mat3 _coord;
	std::vector<Vec3> _vertexs;

	Vec3 _center;
	Vec3 _extent;
	Vec3 _scale;
};