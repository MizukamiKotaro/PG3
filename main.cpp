#include <stdio.h>
#include <iostream>
#include <string>
#include <chrono>

template <typename T>
void Comment(T comment) {
	std::cout << comment << std::endl;
}

int main() {
	
	std::string a(1000000, 'a');

	std::string b;

	std::chrono::steady_clock::time_point startTime = std::chrono::steady_clock::now();

	b = a;

	std::chrono::steady_clock::time_point endTime = std::chrono::steady_clock::now();

	std::chrono::microseconds time = std::chrono::duration_cast<std::chrono::microseconds>(endTime - startTime);

	Comment(time);

	startTime = std::chrono::steady_clock::now();

	b = std::move(a);

	endTime = std::chrono::steady_clock::now();

	time = std::chrono::duration_cast<std::chrono::microseconds>(endTime - startTime);

	Comment(time);

	return 0;
}
