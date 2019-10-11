#include "SeaSquare.h"

SeaSquare::SeaSquare():x_size(5),y_size(5) {
	InitializeSquare();
}

SeaSquare::SeaSquare(int x) : x_size(x), y_size(x) {
	InitializeSquare();
}

SeaSquare::SeaSquare(int x, int y) : x_size(x), y_size(y) {
	InitializeSquare();
}

void SeaSquare::InitializeSquare() {
	blocks = new SeaBlock * [x_size];
	for (int i = 0; i < x_size; i++) {
		blocks[i] = new SeaBlock[y_size];
	}

	for (int i = 0; i < x_size; i++) {
		for (int j = 0; j < y_size; j++)
		{
			if (i > 0)
				blocks[i][j].set_west_block(&blocks[i - 1][j]);
			if (i < x_size - 1)
				blocks[i][j].set_east_block(&blocks[i + 1][j]);
			if (j > 0)
				blocks[i][j].set_north_block(&blocks[i][j - 1]);
			if (j < y_size - 1)
				blocks[i][j].set_south_block(&blocks[i][j + 1]);
		}
	}
}


