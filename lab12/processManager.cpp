#include <iostream>
#include <queue>

using namespace std;

#include "process.h"
#include "processManager.h"
#include "processHistory.h"

extern ProcessHistory ProcessHistory;

bool ProcessManager::doLogic()
{
	if(strategy)
		return (strategy->doLogic());
	else
		return false;
}

void ProcessManager::createNewProcess(unsigned int steps)
{
	if(strategy)
		strategy->createNewProcess(steps);
}

void ProcessManager::setStrategy(Strategy *strategy)
{
	this->strategy = strategy;
}