#pragma once
#include "Vector.h"

class Camera {
public:
	Camera() :_eye(10.0f, 10.0f, 10.0f), _at(0.0f, 0.0f, 0.0f), _perspective(0.0f,100.0f,0.8f){}


	void SetView(const Vec3 &v1, const Vec3 &v2) { _eye = v1; _at = v2; }
	Vec3 GetEye() { return _eye; }
	Vec3 GetAt() { return _at; }

	void SetPerspective(const Vec3 &v) { _perspective = v; }
	Vec3 GetPerspective() { return _perspective; }

private:
	Vec3 _eye, _at, _perspective;
};