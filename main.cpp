#include <stdio.h>

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



int main() {

	printf("%d\n", Syachiku(0, 0, 0));

	return 0;
}
