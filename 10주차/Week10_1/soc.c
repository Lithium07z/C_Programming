#include <stdio.h>

int add(int a, int b); // �Լ� add()�� ����
void fun1() {
	int (*fpt)(int a, int b); // �Լ� ������ ���� : add()�� ����Ű�� ����
	int a, b, sum;
	a = 10;
	b = 20;
	fpt = add; // add() �Լ��� ���� �ּҸ� �Ҵ��Ѵ�
	sum = fpt(a, b); // �Լ� ������ fpt�� �̿��� add()�� ȣ���Ѵ�
	printf("sum = %d\n", sum);

	return 0;
}
// �Լ� add()�� ���� 
int add(int a, int b) {
	return a + b;
}