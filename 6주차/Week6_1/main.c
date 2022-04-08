#include "fun.h"

void main(void) {
	fun1();
	fun2();
	fun3();
	int data[] = { 90, 100, -5, 65, 34, 20, 15, 7,10, 85 };
	int tot;

	tot = eSum(data, 10); // 값이 담긴 배열이랑 배열 크기를 넘겨주고 eSum함수에서 리턴해준 총합을 tot에 넣음
	printf("\n배열의 총합은 %d입니다. \n", tot);
}