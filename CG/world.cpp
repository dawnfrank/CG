#include "world.h"

World::World()
{
	_InitWorld();
}

World::~World()
{
	_DeInitWorld();
}

void World::_InitWorld()
{
	_camera = new Camera();
	_box = new Box();
}

void World::_DeInitWorld()
{
	delete _camera;
	delete _box;
}
