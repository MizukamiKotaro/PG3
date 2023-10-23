#pragma once
#include "../Hololive.h"

class Marin : public Hololive
{
public:
	Marin();
	~Marin() override;

	void Greeting() override;
};

