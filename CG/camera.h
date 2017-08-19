#pragma once
#include "Vector.h"

class Camera {
public:
	Camera();
	~Camera();

	void SetView();
	void GetView();
private:
	Vec3 eye, at, up;
};