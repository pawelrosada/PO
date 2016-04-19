// program11.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include "Baubles.h"
#include "Candles.h"
#include "Star.h"
#include "Tree.h"
#include <ctime>
#include <time.h>

int _tmain(int argc, _TCHAR* argv[])
{
	srand((unsigned int)time(NULL));
	Baubles* bauble = new Baubles;
	Candles* candle = new Candles;
	Star* star= new Star;

	bauble->Draw();
	candle->Draw();
	star->Draw();
	system("pause");
	return 0;
}

