#pragma once
#include "../Hololive.h"

class Hazime : public Hololive
{
public:
	Hazime();
	~Hazime() override;

	void Greeting() override;
};

