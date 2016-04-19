#pragma once

enum ProcessState
{
	PROCESS_WORKING,
	PROCESS_STOPPED,
	PROCESS_FINISHED
};

class Process
{
public:
	Process(unsigned int _id, unsigned int steps);
	~Process() { };
	unsigned int getID();
	unsigned int getStepTime();
	unsigned int getRemainingSteps();
	void setState(enum ProcessState _state);
	enum ProcessState getState();
	void doStep();
private:
	unsigned int id;
	ProcessState state;
	unsigned int totalStepsNumber;
	unsigned int remainingSteps;
	unsigned int nextStepTime;
};