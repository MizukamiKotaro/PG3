#pragma once
#include <string>

class Hololive
{
public:

	Hololive();

	virtual ~Hololive();

	virtual void Greeting();

protected:
	
	std::string name_;
};

