#include "stdafx.h"
#include <sstream>
#include "ProcessesHistory.h"


ProcessesHistory::ProcessesHistory(int number)
{
	allProcesses = new history[number];
}
void ProcessesHistory::setHistory(Process *name)
{
	string tmp = name->getProcessState();
	allProcesses[name->getProcessId()].processId = name->getProcessId();
	allProcesses[name->getProcessId()].state.push_back(tmp[0]);
}
string ProcessesHistory::showHistory(int processNumber, int execute)
{
	ostringstream history;
	history << "000" << allProcesses[processNumber].processId << " ";
		for (int i = 0; i < execute; i++)
			history << allProcesses[processNumber].state[i];
	return history.str();
}
