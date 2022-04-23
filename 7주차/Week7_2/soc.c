#include <stdio.h>

void fun1() {
	int mode;

	do {
		printf("1월 ~ 12월에 해당되는 숫자를 입력하세요 : ");
		scanf_s("%d", &mode);
		if (mode >= 1 && mode <= 12) {
			break;
		}
		printf("%d월은 없습니다. 다시 입력하세요.\n\n", mode);
	} while (mode < 1 || mode > 12); 
		printf("당신은 %d월을 선택하셨습니다. 반갑습니다.\n", mode);
}

int cal1(int b) {
	int i, mul = 1;
	for (i = 1; i <= b; i++) {
		mul *= i;
	}
	return mul;
}

int cal2(int b) {
	return b * b;
}

int cal3(int a, int b) {
	return b % a;
}

void fun2(int a, int b) {
	switch (a) {
	case 1:
		printf("\n1에서 %d까지의 곱셈의 값은 %d입니다.\n", b, cal1(b));
		break;
	case 2:
		printf("%d^2의 값은 %d입니다.\n", b, cal2(b));
		break;
	default:
		printf("%d를 %d로 나눈 나머지 값은 %d입니다.\n", a, b, cal3(a, b));
		break;
	}
}

void fun2_main() {
	fun2(1, 10);
	fun2(2, 5);
	fun2(3, 10);
	fun2(4, 20);
}

void fun3() {
	int data[5];
	int i, j;
	char msg[][5] = { "첫", "두", "세", "네", "다섯" };
	
	printf("\n[데이터 입력]\n");
	for (i = 0; i < 5; i++) {
		printf("%s번째 데이터 : ", msg[i]);
		scanf_s("%d", &data[i]);
	}
	printf("\n[출력형식]\n-------------------------------\n");
	for (i = 0; i < 5; i++) {
		printf("%s번째 데이터\t:", msg[i]);
		for (j = 1; j <= data[i] / 10; j++) {
			printf("■ ");
		}
		printf("(%d)\n", data[i]);
	}
	printf("-------------------------------\n");
}