#pragma once
#include "../IShape.h"

class Rectangle : public IShape
{
public:

	Rectangle(float height, float width);
	void CalcArea() override;
	void Draw() override;
};

