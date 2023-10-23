#include "Hololive.h"
#include <iostream>

Hololive::Hololive()
{
	name_ = "Holo";
}

Hololive::~Hololive()
{
	std::cout << name_ << "'s finished delivery." << std::endl;
}

void Hololive::Greeting()
{
	std::cout << name_ << " does greeting." << std::endl;
}
