#include <stdio.h>
#define SQUARE(n) n * n; // ��ũ�� �Լ� 

void fun1(void) {
	int result = SQUARE(3); // ��ũ�� �Լ� SQUARE�� 3�� �־����Ƿ� 3 * 3�� ���� 9�� result�� ��
	//printf("%d\n", result); //����ϰ� �Ǹ� 9�� ��µ�
}

#define PRINT(x) printf(#x"= %d\n", x) // #������ ���ڿ� ����� �� ���� �����̸�= %d~~�� ������� ��µ�
void fun2(void) {
	int num = 10;
	int su = 20;

	PRINT(num);
	PRINT(su);
}

#define MAKE_FUNC(name) fn##name() // fn���� �����ϸ� ���ڷ� ���� name�� ���� �̸��� ���� �Լ��� ȣ����
void fntest1(void) {               // Ex. ���ڷ� test1�� ���� ��� fn + test1�̹Ƿ� fntest1 �Լ��� ȣ����
	printf("test1ȣ��\n");
}

void fntest2(void) {
	printf("test2ȣ��\n");
}

void fnMain(void) {
	MAKE_FUNC(test1);
	MAKE_FUNC(test2);
}