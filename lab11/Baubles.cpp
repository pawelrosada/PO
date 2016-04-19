#include "stdafx.h"
#include "Baubles.h"
#include <random>
void Baubles::Draw()
{
	size = rand() % 6 + 10;
	drawTree(ornament);
}