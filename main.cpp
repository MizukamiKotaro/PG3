#include <stdio.h>
#include <random>
#include <chrono>
#include <thread>
#include <string>
#include <iostream>
#include <functional>
#include "Enemy/Enemy.h"
#include "Hoge/Hoge.h"
#include "Hololive/Member/Marin.h"
#include "Hololive/Member/Pekora.h"
#include "Hololive/Hololive.h"
#include "Shape/IShape.h"
#include "Shape/Shapes/Circle.h"
#include "Shape/Shapes/Rectangle.h"
#include <string>

template <typename T>
T min(T a,T b) {
	if (a < b) {
		return a;
	}
	else {
		return b;
	}
}

template <>
char min<char>(char a, char b) {
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

typedef int (*newType)();
typedef void (*PFunc)(int, int);

//int DicePip() { 
//	std::random_device dice;
//	return dice() % 6 + 1;
//}

int Input() {

	int answer;

	while (true) {
		printf("丁の場合1を、半の場合２を入力してEnterを押してください\n");

		std::cin >> answer;
		
		if (answer == 1 || answer == 2) {
			return answer;
		}

		printf("〇ね\n");
		std::cin.clear();
		std::cin.seekg(0);

	}

}

void ChoHan(PFunc p, int second) {

	newType hoge;

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

template <typename T>
void Comment(T comment) {
	std::cout << comment << std::endl;
}

int main() {

	std::string str = "斜め七十七度の並びに泣く泣くいななく七藩七代難なく眺めてながながめ～";

	printf("%s", str.c_str());

	return 0;
}
