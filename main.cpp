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

int main() {

	int min0 = min<int>(114, 514);
	printf("%d\n", min0);
	float min1 = min<float>(11.4f, 51.4f);
	printf("%f\n", min1);
	double min2 = min(11.4, 51.4);
	printf("%lf\n", min2);
	char min3 = min<char>('114', '514');
	printf("%c", min3);

	return 0;
}
