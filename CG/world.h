#pragma once

#include "camera.h"
#include "Box.h"

class World {
public:
	World();
	~World();

private:
	void _InitWorld();
	void _DeInitWorld();

	Camera *_camera;
	Box *_box;
};