#include "Box.h"

Box::Box():_center(0.0f,0.0f,0.0f),_extent(1.0f,1.0f,1.0f),_scale(1.0f,1.0f,1.0f)
{
	_vertexs.resize(8);
}
