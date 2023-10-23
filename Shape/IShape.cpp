#include "IShape.h"
#include <iostream>

IShape::IShape()
{
	name_ = "Shape";
	radius_ = 1.0f;
	height_ = 1.0f;
	width_ = 1.0f;
	area_ = 1.0f;
}

IShape::~IShape()
{
	std::cout << name_ << " was deleted." << std::endl;
}

void IShape::CalcArea() 
{
	area_ = height_ * width_;
}

void IShape::Draw() 
{
	std::cout << name_ << "'s area is " << area_ << "." << std::endl;
}