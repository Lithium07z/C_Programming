#include "fun.h"

void main(void) {
	fun1();
	fun2();
	fun3();
	int data[] = { 90, 100, -5, 65, 34, 20, 15, 7,10, 85 };
	int tot;

	tot = eSum(data, 10); // ���� ��� �迭�̶� �迭 ũ�⸦ �Ѱ��ְ� eSum�Լ����� �������� ������ tot�� ����
	printf("\n�迭�� ������ %d�Դϴ�. \n", tot);
}