#include <stdio.h>
#include <random>
#include <chrono>
#include <thread>
#include <iostream>
#include <functional>

void SetTimeout(std::function<void()> func, int second) {

	std::this_thread::sleep_for(std::chrono::milliseconds(second * 1000));

	func();
}

int main() {

	int answer;
	int diceNum;

	std::function<int()> Input = []() {
		int answer;
		while (true) {
			printf("丁の場合1を、半の場合２を入力してEnterを押してください\n");

			std::cin >> answer;

			if (answer == 1 || answer == 2) {
				return answer;
			}

			printf("正しく入力してください\n");
			std::cin.clear();
			std::cin.seekg(0);
		}
	};

	std::function<int()> DicePip = []() {
		std::random_device dice;
		return dice() % 6 + 1;
	};

	std::function<void()> Answer = [&]() {
		if (answer == (diceNum) % 2 + 1) {
			if ((diceNum) % 2 == 0) {
				printf("%dの丁で正解\n", diceNum);
			}
			else {
				printf("%dの半で正解\n", diceNum);
			}
		}
		else {
			if ((diceNum) % 2 == 0) {
				printf("%dの丁で不正解\n", diceNum);
			}
			else {
				printf("%dの半で不正解\n", diceNum);
			}
		}
	};
	
	while (true)
	{

		answer = Input();
		diceNum = DicePip();

		SetTimeout(Answer, 3);
	}

	return 0;
}



