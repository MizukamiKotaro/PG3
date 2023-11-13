#include <stdio.h>
#include <random>
#include <chrono>
#include <thread>
#include <iostream>
#include <functional>

typedef void (*PFunc)(int, int);

void Answer(int answer, int dice) {

	if (answer == (dice) % 2 + 1) {
		if ((dice) % 2 == 0) {
			printf("%dの丁で正解\n", dice);
		}
		else {
			printf("%dの半で正解\n", dice);
		}
	}
	else {
		if ((dice) % 2 == 0) {
			printf("%dの丁で不正解\n", dice);
		}
		else {
			printf("%dの半で不正解\n", dice);
		}
	}
}

int main() {

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

	int answer;
	int diceNum;

	std::function<void(PFunc, int)> SetTimeout = [&](PFunc afterPFunc, int second) {
		std::this_thread::sleep_for(std::chrono::milliseconds(second * 1000));
		afterPFunc(answer, diceNum);
	};
	
	while (true)
	{

		answer = Input();
		diceNum = DicePip();

		SetTimeout(Answer, 3);
	}

	return 0;
}
