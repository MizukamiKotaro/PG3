#pragma once
#include <string>

class IShape
{
public:

	IShape();

	virtual ~IShape() = 0;

	virtual void CalcArea() = 0;

	virtual void Draw() = 0;

protected:
	
	std::string name_;

	float radius_;

	float height_;

	float width_;

	float area_;
};

