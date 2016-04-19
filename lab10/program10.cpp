// program10.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include "Manager.h"
#include "ProcessesHistory.h"

int _tmain(int argc, _TCHAR* argv[])
{
	Manager newProcess(5);
	ProcessesHistory *history;

	for (int i = 0; i < 5; i++)
	{
		int stepsNumber = rand() % 15, processTime= rand() % 5;
		newProcess.addProcess(stepsNumber, processTime);
	}
	int counter=0;
	while (newProcess.getEnd() == false)
	{
		newProcess.makeHistory();
		newProcess.processExecution();
		counter++;
	}
	history = newProcess.getHistory();
	for (int i = 0; i < 5; i++)
		cout << history->showHistory(i, newProcess.getExecutions()) << endl;

	cout << endl << endl;
	delete history;
	Manager newProcess2(10);

	for (int i = 0; i < 10; i++)
	{
		int stepsNumber = rand() % 10, processTime = rand() % 5;
		newProcess2.addProcess(stepsNumber, processTime);
	}
	counter = 0;
	
	while (newProcess2.getEnd() == false)
	{
		newProcess2.makeHistory();
		newProcess2.processExecution();
		counter++;
	}
	history = newProcess.getHistory();
	for (int i = 0; i < 10; i++)
		cout << history->showHistory(i, newProcess2.getExecutions()) << endl;

	system("pause");
	return 0;
}

