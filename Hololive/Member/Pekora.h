#pragma once
#include "../Hololive.h"

class Pekora : public Hololive
{
public:
	Pekora();
	~Pekora() override;

	void Greeting() override;
};

