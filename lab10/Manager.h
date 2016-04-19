#include <list>
#include <string>

#include "Process.h"
#include "ProcessesHistory.h"
using namespace std;

#pragma once
class Manager
{
private:
	list <Process*> processList;
	int lastProcessId;
	int processorTime;
	bool end;
	int numberExecutions;
	ProcessesHistory *newHistory;
public:
	Manager(int);
	void addProcess(int ,int);
	void processExecution();
	void makeHistory();
	bool getEnd();
	ProcessesHistory * getHistory();
	int getExecutions();
};

