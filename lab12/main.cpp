#include <iostream>
#include <Windows.h>
#include <time.h>

using namespace std;

#include "process.h"
#include "processManager.h"
#include "processHistory.h"
#include "sjf.h"
#include "fifo.h"

ProcessHistory ProcessHistory;
ProcessManager ProcessManager;

std::string intToStr(int n)
{
     std::string tmp;
     if(n < 0) {
          tmp = "-";
          n = -n;
     }
     if(n > 9)
          tmp += intToStr(n / 10);
     tmp += n % 10 + 48;
     return tmp;
}

int main()
{
	srand(123456);

	Fifo *fifo = new Fifo();
	Sjf *sjf = new Sjf();

	////////////////
	//FIFO
	//////////////
	cout << "FIFO" << endl;
	ProcessManager.setStrategy(fifo);
	for(unsigned int i = 0; i < 10; i++)
	{
		int random = rand() % 3 + 1;
		ProcessManager.createNewProcess(random);
	}

	bool isDone = true;

	while(isDone)
		isDone = ProcessManager.doLogic();

	std::string entries = ProcessHistory.getAllEntries();
	
	cout << entries << endl;

	srand(123456);
	ProcessHistory.clear();
	////////////////
	//SJF
	//////////////
	cout << "SJF" << endl;
	ProcessManager.setStrategy(sjf);
	for(unsigned int i = 0; i < 10; i++)
	{
		int random = rand() % 3 + 1;
		ProcessManager.createNewProcess(random);
	}

	isDone = true;

	while(isDone)
		isDone = ProcessManager.doLogic();

	entries = ProcessHistory.getAllEntries();
	
	cout << entries << endl;

	system("PAUSE");
	return 1;
}