#pragma once

#include <list>
#include "strategy.h"
#include "process.h"


class Sjf : public Strategy
{
private:
	std::list<Process*> processesList;
	static unsigned int currentProcessID;
	int lastProcessedProcessID;
	int  lastCreatedProcessID;
public:
	Sjf();
	bool doLogic();
	void createNewProcess(unsigned int steps);
};