#include "Hololive.h"
#include <iostream>

Hololive::Hololive()
{
}

Hololive::~Hololive()
{
	std::cout << name_ << "の配信が終わった。" << std::endl;
}

void Hololive::Greeting()
{
	std::cout << name_ << "の挨拶。" << std::endl;
}
