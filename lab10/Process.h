#include <string>
using namespace std;
#pragma once
class Process
{
private:
	int processId;
	string processState;
	int stepsNumber;
	int remainingSteps;
	int stepsTime;
public:
	Process(int, string, int, int);
	int getProcessId();
	int getStepsNumber();
	void setRemainingSteps(int);
	int getRemainingSteps();
	void setStepsTime(int);
	int getStepsTime();
	string getProcessState();
	void setProcessState(string);
	~Process();
};

