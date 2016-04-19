#include "stdafx.h"
#include "Process.h"


Process::Process(int _processId, string _processState, int _stepsNumber, int _stepsTime)
{
	processId = _processId;
	processState = _processState;
	stepsNumber = _stepsNumber;
	remainingSteps = stepsNumber;
	stepsTime = _stepsTime;
}

int Process::getProcessId()
{
	return processId;
}
int Process::getStepsNumber()
{
	return stepsNumber;
}
void Process::setRemainingSteps(int steps)
{
	remainingSteps -= steps;
}
void Process::setStepsTime(int time)
{
	stepsTime = time;
}
void Process::setProcessState(string state)
{
	processState = state;
}
int Process::getRemainingSteps()
{
	return remainingSteps;
}
int Process::getStepsTime()
{
	return stepsTime;
}
string Process::getProcessState()
{
	return processState;
}
Process::~Process()
{
}
