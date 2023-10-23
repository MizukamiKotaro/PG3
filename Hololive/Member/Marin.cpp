#include "Marin.h"
#include <iostream>

Marin::Marin()
{
	name_ = "HousyoMarin";
}

Marin::~Marin()
{
}

void Marin::Greeting()
{
	std::cout << "Ahoy~" << std::endl;
}
