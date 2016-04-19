#include "stdafx.h"
#include "Manager.h"


Manager::Manager(int numbers)
{
	lastProcessId = 0;
	processorTime = rand() % 5 + 10;
	numberExecutions = 0;
	end = false;
	newHistory = new ProcessesHistory(numbers);
}

void Manager::addProcess(int stepsNumber, int processTime)
{
	Process *newProcess = new Process(lastProcessId, "Wstrzymany",stepsNumber, processTime);
	lastProcessId++;
	processList.push_back(newProcess);
}
void Manager::makeHistory()
{
	int i = 0;
	int counter = 0;
	list <Process *>::iterator iterator;
	for (iterator = processList.begin(); iterator != processList.end(); ++iterator)
	{
		Process *tmp = *iterator;
		string pom = tmp->getProcessState();
		if (pom == "Zakonczony")
			counter++;
		newHistory->setHistory(tmp);
	}
	if (counter == processList.size())
		end = true;
	numberExecutions++;
}
void Manager::processExecution()
{
	int processTmp = processorTime;
	list <Process *> tmpProcessList=processList;
	list <Process *>::iterator iterator;
	for (iterator = processList.begin(); iterator != processList.end(); ++iterator)
	{
		Process *tmp = *iterator;
		if (tmp->getProcessState() != "Zakonczony")
		{
			while (processorTime >= 0)
			{
				if (processorTime >= tmp->getStepsTime())
					tmp->setRemainingSteps(1);
				processorTime -= tmp->getStepsTime();
				tmp->setProcessState("Dziala");
				if (tmp->getProcessState() == "Dziala")
				{
					tmpProcessList.remove(tmp);
					tmpProcessList.push_back(tmp);
				}
				if (tmp->getRemainingSteps() <= 0)
				{
					tmp->setProcessState("Zakonczony");
					break;
				}
				makeHistory();
			}
		}
		if (tmp->getProcessState() != "Zakonczony")
			tmp->setProcessState("Wstrzymany");
	}
	//makeHistory();
	processList = tmpProcessList;
	processorTime = processTmp;
}
bool Manager::getEnd()
{
	return end;
}
int Manager::getExecutions()
{
	return numberExecutions;
}
ProcessesHistory* Manager::getHistory()
{
	return newHistory;
}