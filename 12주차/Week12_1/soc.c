#include <stdio.h>
#define SQUARE(n) n * n; // 매크로 함수 

void fun1(void) {
	int result = SQUARE(3); // 매크로 함수 SQUARE에 3을 넣었으므로 3 * 3의 값인 9가 result에 들어감
	//printf("%d\n", result); //출력하게 되면 9가 출력됨
}

#define PRINT(x) printf(#x"= %d\n", x) // #때문에 문자열 상수가 됨 따라서 인자이름= %d~~의 방식으로 출력됨
void fun2(void) {
	int num = 10;
	int su = 20;

	PRINT(num);
	PRINT(su);
}

#define MAKE_FUNC(name) fn##name() // fn으로 시작하며 인자로 받은 name을 붙인 이름을 가진 함수를 호출함
void fntest1(void) {               // Ex. 인자로 test1을 받은 경우 fn + test1이므로 fntest1 함수를 호출함
	printf("test1호출\n");
}

void fntest2(void) {
	printf("test2호출\n");
}

void fnMain(void) {
	MAKE_FUNC(test1);
	MAKE_FUNC(test2);
}