#include "stdafx.h"
#include "Candles.h"
#include <random>
void Candles::Draw()
{
	size = rand() % 6+10;
	drawTree(ornament);
}