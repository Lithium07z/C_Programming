#include <stdio.h>
int add(int a, int b);
int sub(int a, int b);
int mul(int a, int b);
int div(int a, int b);

void fun1() {
	int(*fpt[4])(int a, int b); // �Լ� ������ �迭
	int a, b, res, num;
	fpt[0] = add; // add()�Լ��� ���� �ּ� ����
	fpt[1] = sub; // sub()�Լ��� ���� �ּ� ����
	fpt[2] = mul; // mul()�Լ��� ���� �ּ� ����
	fpt[3] = div; // div()�Լ��� ���� �ּ� ����
	do {
		printf("1. add, 2. sub, 3. mul, 4. div, 5. exit : ");
		scanf_s("%d", &num);
		if (num == 5) {
			break;
		}
		printf("\nInput number for a, b : \n");
		scanf_s("%d %d", &a, &b);
		res = fpt[num - 1](a, b); // �Լ� ������ �迭�� �̿��� �Լ� ȣ��� ��� ���
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