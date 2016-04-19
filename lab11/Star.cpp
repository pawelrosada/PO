#include "stdafx.h"
#include "Star.h"
#include <random>
void Star::Draw()
{
	size = rand() % 6+10;
	drawTree(ornament);
}