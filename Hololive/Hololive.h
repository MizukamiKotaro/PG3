#pragma once
#include <string>

class Hololive
{
public:

	Hololive();

	virtual ~Hololive();

	virtual void Greeting();

protected:
	// const にすると代入演算子がないと言われる
	std::string name_;
};

