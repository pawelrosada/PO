#pragma once

class Strategy
{
public:
	virtual bool doLogic() = 0;
	virtual void createNewProcess(unsigned int steps) = 0;
};