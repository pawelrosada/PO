#pragma once
#include <string>
#include <vector>
#include "Process.h"
using namespace std;

class ProcessesHistory
{
private:
	struct history
	{
		int processId;
		vector <char> state;
	};
	history *allProcesses;
public:
	ProcessesHistory(int);
	void setHistory(Process *);
	string showHistory(int, int);
};

