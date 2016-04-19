#pragma once

#include <string>
#include <map>

class Process;
enum ProcessState;

class ProcessHistory
{
public:
	ProcessHistory() { };
	~ProcessHistory() { };
	void addProcessHistory(unsigned int processID, ProcessState state);
	bool createProcessHistory(unsigned int processID);
	std::string ProcessHistory::getAllEntries();
	void clear();
private:
	std::map<int, std::string> processesHistory;
};