#pragma once
#include "../IShape.h"

class Circle : public IShape
{
public:

	Circle(float radius = 1.0f);
	void CalcArea() override;
	void Draw() override;
};

