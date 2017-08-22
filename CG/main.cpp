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

	Vec3 boxPos,boxCameraPos;
	Mat3 matrixCamera;

	while (r.Run()) {
		r.Paint();

		boxPos = pBox->GetCenter();
		matrixCamera = pCamera->GetCoord();
		boxCameraPos = matrixCamera*boxPos;
	}

	return 0;
}