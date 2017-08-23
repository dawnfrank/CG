#include <iostream>
#include <chrono>

#include "world.h"
#include "renderer.h"

int main() {
	Renderer r;
	auto w = r.OpenWindow(800, 600, "test");

	World *pWorld = r.GetWorld();
	Camera *pCamera = pWorld->GetCamera();
	Box *pBox = pWorld->GetBox();

	Mat3 CameraProj=Mat3(Vec3(1,0,0), Vec3(0,1,0), Vec3(0,0,0)).inverse();
	Mat3 matrixCamera = pCamera->GetCoord();

	auto vertexs = pBox->GetVertex();
	for (auto &v : vertexs) {
		v = CameraProj*matrixCamera*v;
	}

	while (r.Run()) {
		r.Paint();
	}

	return 0;
}