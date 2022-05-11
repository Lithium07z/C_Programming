#include <stdio.h>

int add(int a, int b); // 함수 add()의 원형
void fun1() {
	int (*fpt)(int a, int b); // 함수 포인터 선언 : add()를 가리키기 위해
	int a, b, sum;
	a = 10;
	b = 20;
	fpt = add; // add() 함수의 시작 주소를 할당한다
	sum = fpt(a, b); // 함수 포인터 fpt를 이용해 add()를 호출한다
	printf("sum = %d\n", sum);

	return 0;
}
// 함수 add()의 정의 
int add(int a, int b) {
	return a + b;
}