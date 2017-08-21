#pragma once

#include "camera.h"
#include "Box.h"

class World {
public:
	World();
	~World();

	Camera *GetCamera() { return _camera; }
	Box *GetBox() { return _box; }

private:
	void _InitWorld();
	void _DeInitWorld();

	Camera *_camera;
	Box *_box;
};