#pragma once
#include "Matrix.h"

class Camera {
public:
	Camera() :_eye(10.0f, 10.0f, 10.0f), _at(0.0f, 0.0f, 0.0f), _perspective(0.0f,100.0f,0.8f){}


	void SetView(const Vec3 &v1, const Vec3 &v2) { _eye = v1; _at = v2; }
	Vec3 GetEye() { return _eye; }
	Vec3 GetAt() { return _at; }

	void SetPerspective(const Vec3 &v) { _perspective = v; }
	Vec3 GetPerspective() { return _perspective; }

	Mat3x3 GetCoord() {
		auto z = (_eye - _at).Normalize();
		auto x = z.Cross(Vec3(0.0f, 1.0f, 0.0f));
		auto y = x.Cross(z);
		return Mat3x3(x, y, z);
	}

private:
	Vec3 _eye, _at, _perspective;
};