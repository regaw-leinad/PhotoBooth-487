#include "PhotoBooth487.h"

const int CAMERA_WIDTH = 800;
const int CAMERA_HEIGHT = 600;

int main(int argc, char *argv[]) {
	PhotoBooth487 photoBooth(CAMERA_WIDTH, CAMERA_HEIGHT);
	photoBooth.start();

	return 0;
}
