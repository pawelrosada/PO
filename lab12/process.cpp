#include <iostream>
#include <time.h>
#include "process.h"

Process::Process(unsigned int _id, unsigned int steps)
{ 
	id = _id;
	state = PROCESS_WORKING;
	totalStepsNumber = steps;
	remainingSteps = steps;
	nextStepTime = rand() % 3 + 1;

	//std::cout << "num: " << nextStepTime << std::endl;
};

unsigned int Process::getID()
{
	return id;
}

unsigned int Process::getStepTime()
{
	return nextStepTime;
}

unsigned int Process::getRemainingSteps()
{
	return remainingSteps;
}

void Process::setState(enum ProcessState _state)
{
	state = _state;
}

enum ProcessState Process::getState()
{
	return state;
}

void Process::doStep()
{
	remainingSteps -= 1;
	nextStepTime = rand() % 3 + 1;
}