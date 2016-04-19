#include <iostream>
#include <map>

using namespace std;

#include "process.h"
#include "processManager.h"
#include "processHistory.h"

extern std::string intToStr(int n);

void ProcessHistory::addProcessHistory(unsigned int processID, ProcessState state)
{
	std::map<int,string>::iterator it = processesHistory.begin();
	while(it != processesHistory.end())
	{
		if(it->first == processID)
		{
			switch(state)
			{
				case PROCESS_WORKING:
					it->second += "W";
				break;

				case PROCESS_STOPPED:
					it->second += "S";
				break;

				case PROCESS_FINISHED:
					it->second += "F";
				break;
			}
		}
		else
		{
			if(it->second.empty() == false && (/*it->second.back() == 'W' ||*/ it->second.back() == 'F'))
				it->second += "F";
			else
				it->second += "S";
		}
		++it;
	}
}

bool ProcessHistory::createProcessHistory(unsigned int processID)
{
	std::map<int,string>::iterator it = processesHistory.find(processID);
	if(it != processesHistory.end())
	{
		cout << "ProcessHistory::Error - can't create process history, allready exist, pid: " << processID << endl;
		return false;
	}
	else
		processesHistory.insert(std::pair<int,string>(processID,""));
	return true;
}

string ProcessHistory::getAllEntries()
{
	std::string entries = "";
	
	std::map<int,string>::iterator it = processesHistory.begin();
	while(it != processesHistory.end())
	{
		if(it->first < 10)
			entries += "0";
		entries += intToStr(it->first);
		entries += ": ";
		entries += it->second;
		entries += "\n";
		++it;
	}
	return entries;
}

void ProcessHistory::clear()
{
	processesHistory.clear();
}