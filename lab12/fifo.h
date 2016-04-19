#pragma once

#include <queue>
#include "strategy.h"
#include "process.h"


class Fifo :public Strategy
{
private:
	std::queue<Process*> processesQueue;
	static unsigned int currentProcessID;
	unsigned int lastCreatedProcessID;
public:
	bool doLogic();
	void createNewProcess(unsigned int steps);
};