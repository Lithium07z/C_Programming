#include <stdio.h>

void fun1() {
	int mode;

	do {
		printf("1�� ~ 12���� �ش�Ǵ� ���ڸ� �Է��ϼ��� : ");
		scanf_s("%d", &mode);
		if (mode >= 1 && mode <= 12) {
			break;
		}
		printf("%d���� �����ϴ�. �ٽ� �Է��ϼ���.\n\n", mode);
	} while (mode < 1 || mode > 12); 
		printf("����� %d���� �����ϼ̽��ϴ�. �ݰ����ϴ�.\n", mode);
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
		printf("\n1���� %d������ ������ ���� %d�Դϴ�.\n", b, cal1(b));
		break;
	case 2:
		printf("%d^2�� ���� %d�Դϴ�.\n", b, cal2(b));
		break;
	default:
		printf("%d�� %d�� ���� ������ ���� %d�Դϴ�.\n", a, b, cal3(a, b));
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
	char msg[][5] = { "ù", "��", "��", "��", "�ټ�" };
	
	printf("\n[������ �Է�]\n");
	for (i = 0; i < 5; i++) {
		printf("%s��° ������ : ", msg[i]);
		scanf_s("%d", &data[i]);
	}
	printf("\n[�������]\n-------------------------------\n");
	for (i = 0; i < 5; i++) {
		printf("%s��° ������\t:", msg[i]);
		for (j = 1; j <= data[i] / 10; j++) {
			printf("�� ");
		}
		printf("(%d)\n", data[i]);
	}
	printf("-------------------------------\n");
}