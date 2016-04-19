#pragma once
#include "Tree.h"
#include "Draw_class.h"
class Star: public Draw_class
{
private:
	char ornament = '*';
public:
	void Draw();
};

