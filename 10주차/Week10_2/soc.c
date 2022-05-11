#include <stdio.h>
int add(int a, int b);
int sub(int a, int b);
int mul(int a, int b);
int div(int a, int b);

void fun1() {
	int(*fpt[4])(int a, int b); // 함수 포인터 배열
	int a, b, res, num;
	fpt[0] = add; // add()함수의 시작 주소 저장
	fpt[1] = sub; // sub()함수의 시작 주소 저장
	fpt[2] = mul; // mul()함수의 시작 주소 저장
	fpt[3] = div; // div()함수의 시작 주소 저장
	do {
		printf("1. add, 2. sub, 3. mul, 4. div, 5. exit : ");
		scanf_s("%d", &num);
		if (num == 5) {
			break;
		}
		printf("\nInput number for a, b : \n");
		scanf_s("%d %d", &a, &b);
		res = fpt[num - 1](a, b); // 함수 포인터 배열을 이용한 함수 호출로 결과 얻기
		printf("result = %d\n", res);
	} while (1);

	return 0;
}

int add(int a, int b) {
	return a + b;
}

int sub(int a, int b) {
	return a - b;
}

int mul(int a, int b) {
	return a * b;
}

int div(int a, int b) {
	return a / b;
}