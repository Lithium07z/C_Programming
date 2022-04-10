#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void dfun1(void) {
	char str[] = { 'H', 'e', 'l', 'l', 'o', 0};
	// str�迭�� ���� �ϳ��� ����, �������� null���� 0���� ���Ƿ� ��������
	printf("�Էµ� ���ڿ� : %s\n", str);
}

void dfun2(void) {
	char str[5];

	printf("���ڿ��� �Է��ϼ��� : ");
	scanf_s("%s", str, sizeof(str)); // scanf_s ������� �Է°��� �־ ������ ���� sizeof(str)�� �Է°��� ũ�⸦ ����
	printf("�Էµ� ���ڿ� : %s\n", str);
}

void dfun3(char str[]) { // �Ű������� �޴� �迭�� �״�� ��� 
	printf("�Էµ� ���ڿ� : %s\n", str);
}

char msg[] = "Hello";
void dfun4(char str[]) { // �������� msg�� �Ű������� �޴� �迭�� �״�� ���
	printf("%s : %s\n", msg, str);
}

void dfun5(void) {
	int x, y, tmp;

	x = 10; 
	y = 20;
	printf("x = %d, y = %d\n", x, y); 

	tmp = x; // �ӽú����� x�� ����
	x = y; // x�� y�� ���� 
	y = tmp; // y�� �ӽ������ x ����

	printf("x = %d, y = %d\n", x, y);
}

void dfun6(int x, int y) {
	int tmp;

	tmp = x; // �ӽú����� x�� ����
	x = y; // x�� y�� ���� 
	y = tmp; // y�� �ӽ������ x ����
	// ���������� ��ü�� ������ �װ� ���� �ݿ����� ������
	printf("x = %d, y = %d\n", x, y); // �Լ� ���ο��� �ٲ����� main���� ����� �ȹٲ�
}

void dfun7(int d[]) {
	int tmp;

	tmp = d[0]; // �迭 0��° ���� �ӽú����� ���� 
	d[0] = d[1]; // �迭 1��° ���� 0��°�� ����
	d[1] = tmp; // �迭 1��°�� �ӽú��� �� ����

	printf("dfun7 :  x = %d, y = %d\n", d[0], d[1]);
}

void dfun7_main(void) {
	int arr[2];

	arr[0] = 10; 
	arr[1] = 20;

	printf("x = %d, y = %d\n", arr[0], arr[1]);

	dfun7(arr); // dfun7�Լ��� ���� ��ȯ�� �� ���� ���� �迭�� �Ѱ���

	printf("x = %d, y = %d\n", arr[0], arr[1]);
}

void dfun8(int arr[], int cnt) {
	int i, sum;

	sum = 0; // �迭 ���� �������� ���� 
	for (i = 0; i < cnt; i++) {
		sum += arr[i]; // �迭���� �ϳ��� ������ ������
	}

	printf("�迭�� ���� %d �Դϴ�.\n", sum);
}

void dfun8_main(void) {
	int data[] = { 10, 30, 15, 3, 100, 80, 9, 7 }; // ����� ���ÿ� �ʱ�ȭ
	int cnt;

	cnt = sizeof(data) / sizeof(data[0]); // �迭 ��ü ����Ʈ ���� �迭 �� �� �ϳ��� ����Ʈ�� ������ ��ü ũ�� ����
	printf("�迭�� ũ��� %d \n", cnt);
	dfun8(data, cnt); // �迭�̶� �迭 ũ�� �Ѱ���
}

void dfun9(void) {
	char abc[3][9] = { "������", "�踶����", "�Ҿ�" }; // �� 3�� �ѱ��� 2����Ʈ�� �踶���ư� 4���ڷ� ���� ��ϱ�
	int i; // 8����Ʈ + null�� 1����Ʈ�� 3�� 9���� 2���� �迭�� �����ؾ���

	for (i = 0; i < 3; i++) {
		printf("%s %s\n", msg, abc[i]); // �ռ� ���� ��� ���������� ���� ���
	}
	printf("\n");
}