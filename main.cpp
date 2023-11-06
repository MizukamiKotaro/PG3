#include <stdio.h>
#include <random>
#include <chrono>
#include <thread>
#include <string>
#include <iostream>
#include <functional>

template <typename T>
T minCalc(T a,T b) {
	if (a < b) {
		return a;
	}
	else {
		return b;
	}
}

template <>
char minCalc<char>(char a, char b) {
	printf("数字以外は代入できません");
	return '\n';
}

int Syachiku(int hour, int hourmoney, int money) {

	int money0 = 1072 * (hour + 1);
	
	if (hour == 0) {
		money = 100;
		hourmoney = money;
		hour++;
	}
	else {
		hourmoney = hourmoney * 2 - 50;
		money += hourmoney;
		hour++;
	}

	if (money > money0) {
		return hour;
	}
	else {
		return Syachiku(hour, hourmoney, money);
	}
}

typedef int (*PFuncReInt)();
typedef void (*PFunc)(int, int);

int DicePip() { 
	std::random_device dice;
	return dice() % 6 + 1;
}

int Input() {

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

}

void SetTimeout(PFunc afterPFunc, int second, int param0 = 0, int param1 = 0) {

	std::this_thread::sleep_for(std::chrono::milliseconds(second * 1000));

	afterPFunc(param0, param1);
}

void ChoHan(PFunc p, int second) {

	PFuncReInt hoge;

	std::function<int()> DicePip = []() {std::random_device dice; return dice() % 6 + 1; };

	int dice = DicePip();
	hoge = &Input;
	int answer = hoge();

	std::this_thread::sleep_for(std::chrono::milliseconds(second * 1000));

	p(answer, dice);
}

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
	
	while (true)
	{

		PFuncReInt pFunc = Input;
		int answer = pFunc();

		pFunc = DicePip;
		int diceNum = pFunc();

		SetTimeout(Answer, 3, answer, diceNum);
	}

	return 0;
}
