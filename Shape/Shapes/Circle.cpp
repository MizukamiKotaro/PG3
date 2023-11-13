#include "Circle.h"
#include <iostream>
#include <numbers>
#include <cmath>

Circle::Circle(float radius)
{
	name_ = "Circle";
	radius_ = radius;
	height_ = 1.0f;
	width_ = 1.0f;
	area_ = 1.0f;
}

void Circle::Size()
{
	area_ = std::powf(radius_, 2.0f) * std::numbers::pi_v<float>;
}

void Circle::Draw()
{
	std::cout << name_ << "'s area is " << area_ << "." << std::endl;
}

