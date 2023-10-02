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

	printf("%d\n", min<int>(114, 514));
	printf("%f\n", min<float>(11.4f, 51.4f));
	printf("%f\n", min(11.4f, 51.4f));
	printf("%c", min<char>('114', '514'));

	return 0;
}
