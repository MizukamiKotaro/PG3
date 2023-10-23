#pragma once
#include <string>

class Hololive
{
public:

	Hololive();

	virtual ~Hololive();

	virtual void Greeting();

protected:

	const std::string name_;
};

