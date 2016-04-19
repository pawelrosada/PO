#include <list>
#include "sjf.h"
#include "processHistory.h"

extern ProcessHistory ProcessHistory;

using namespace std;

unsigned int Sjf::currentProcessID = 1;

Sjf::Sjf()
{
	lastProcessedProcessID = -1;
}

void Sjf::createNewProcess(unsigned int steps)
{
	Process *process = new Process(currentProcessID, steps);
	if(process)
	{
		this->lastCreatedProcessID = currentProcessID;
		processesList.push_back(process);
		ProcessHistory.createProcessHistory(process->getID());
		currentProcessID += 1;
	}
}

bool Sjf::doLogic()
{
	Process *toDoStep = NULL;

	unsigned int numObjects = 0;
	for(list<Process*>::iterator it = processesList.begin(); it != processesList.end(); it++)
	{
		if((*it)->getRemainingSteps() > 0)
			numObjects += 1;

		if(toDoStep)
		{
			if( (*it)->getStepTime() < toDoStep->getStepTime() && (lastProcessedProcessID != (*it)->getID() || numObjects == 1) && (*it)->getRemainingSteps() > 0)
				toDoStep = (*it);
		}
		else if( (lastProcessedProcessID != (*it)->getID() || numObjects == 1)  && (*it)->getRemainingSteps() > 0)
			toDoStep = (*it);
	}

	if(toDoStep)
	{
		int lastStepTime = toDoStep->getStepTime();
		toDoStep->doStep();
		lastProcessedProcessID = toDoStep->getID();

		for(int i = 0; i < lastStepTime; i++)
			ProcessHistory.addProcessHistory(toDoStep->getID(), PROCESS_WORKING);

		if(toDoStep->getRemainingSteps() <= 0)
		{
			ProcessHistory.addProcessHistory(toDoStep->getID(), PROCESS_FINISHED);
		}
		else
			ProcessHistory.addProcessHistory(toDoStep->getID(), PROCESS_STOPPED);

		return true;
	}
	else
		return false;
}