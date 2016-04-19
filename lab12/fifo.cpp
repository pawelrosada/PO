#include "fifo.h"
#include "processHistory.h"

extern ProcessHistory ProcessHistory;

unsigned int Fifo::currentProcessID = 1;

void Fifo::createNewProcess(unsigned int steps)
{
	Process *process = new Process(currentProcessID, steps);
	if(process)
	{
		this->lastCreatedProcessID = currentProcessID;
		processesQueue.push(process);
		ProcessHistory.createProcessHistory(process->getID());
		currentProcessID += 1;
	}
}

bool Fifo::doLogic()
{
	int lastStepTime;
	if(processesQueue.empty() == false)
	{
		lastStepTime = processesQueue.front()->getStepTime();
		processesQueue.front()->doStep();
	}
	else
		return false;

	for(unsigned int i = 0; i < lastStepTime; i++)
		ProcessHistory.addProcessHistory(processesQueue.front()->getID(), PROCESS_WORKING);

	if(processesQueue.front()->getRemainingSteps() <= 0)
	{
		ProcessHistory.addProcessHistory(processesQueue.front()->getID(), PROCESS_FINISHED);
		processesQueue.pop();
	}
	else
	{
		ProcessHistory.addProcessHistory(processesQueue.front()->getID(), PROCESS_STOPPED);
		processesQueue.push(processesQueue.front());
		processesQueue.pop();
	}
	return true;
}