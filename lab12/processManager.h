#pragma once

#include <queue>
#include "process.h"
#include "strategy.h"

class ProcessManager
{
public:
	ProcessManager() { processorTime = 100; };
	~ProcessManager() { };
	bool doLogic();
	void setStrategy(Strategy *strategy);
	void createNewProcess(unsigned int steps);
private:
	Strategy *strategy;
	int processorTime;
};