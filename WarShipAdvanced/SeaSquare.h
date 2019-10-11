#pragma once
#include "SeaBlock.h"

class SeaSquare
{
protected:
	int x_size;
	int y_size;
	SeaBlock** blocks;

	virtual void InitializeSquare();

public:
	SeaSquare();
	SeaSquare(int x);
	SeaSquare(int x, int y);

};

