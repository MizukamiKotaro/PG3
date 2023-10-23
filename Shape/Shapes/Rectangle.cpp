#include "Rectangle.h"
#include <iostream>

Rectangle::Rectangle(float height, float width)
{
	name_ = "Rectangle";
	radius_ = 1.0f;
	height_ = height;
	width_ = width;
	area_ = 1.0f;
}

void Rectangle::CalcArea()
{
	area_ = height_ * width_;
}

void Rectangle::Draw()
{
	std::cout << name_ << "'s area is " << area_ << "." << std::endl;
}

