#include "stdafx.h"
#include "Tilemapping.h"


// define Main Level


void TileMapp::setLevel(int width, int height) {
	level.resize(width * height);
	for (int y = 0; y < height; y += 2) {
		for (int x = 0; x < width; x += 2) {

			level[y * width + x] = 0; // top left tile
			level[y * width + x + 1] = 1; // top right tile
			level[(y + 1) * width + x] = 2; // bottom left tile
			level[(y + 1) * width + x + 1] = 3; // bottom right tile
		}
	}
}
void TileMapp::spawnLevel()
{

}
/*
int tileID = getTileIDFunctionWhateverItsCalled();

if (tileID == 0) { // grass
	if (rand() % 2) tileID += 1;
	if (rand() % 2) tileID += tiles_in_one_row;
}*/