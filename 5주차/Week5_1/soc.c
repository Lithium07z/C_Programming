#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void fun1(void) {
		int count = 0; // ���� ī��Ʈ
		int sum = 0; // ����
		int i = 1; // �ݺ�����
		for (; i <= 100; i++) { // 1���� 100����
			if (i % 5 == 0) { // 5�� ����� 
				printf("%d ", i); // ���
				count++; // ���� ����
				sum += i; // ���տ� i�� ����
				if (count % 10 == 0) { // 10�� ������ ��� ���
					printf("\n"); // �� �ٲ� 
				}
			}
		}
		printf("����: %d \n����: %d\n", count, sum);
}

void fun2(int strt, int end, int ip) {
	int count = 0; // ���� ī��Ʈ
	int sum = 0; // ���� 
	
	while (strt <= end) { // strt ���� end ���� �ݺ�
		if (strt % ip == 0) { // strt�� ip�� ������ �� 0�Ǵ� ���� ��� (��� ���)
			printf("%d ", strt);
			count++;
			sum += strt;
			if (count % 10 == 0) {
				printf("\n");
			}
		}
		strt++; // strt ����
	}
	printf("\n����: %d \n����: %d\n", count, sum);
	printf("--------------------------------\n");
}

void fun3(int cnt, char word) { // �Լ� ȣ��� �ݺ� Ƚ���� �ݺ��� ���ڸ� ����
	int i; // �ݺ�����
	for (i = 0; i < cnt; i++) { // �Է¹��� Ƚ�� ��ŭ �ݺ�����
		printf("%c", word); // ���
	}
	printf("\n");
}

void fun4(char str[]) { // �Լ� ȣ��� ���ڿ� ���� 
	printf("%s\n", str); // �״�� ��� 
}

void conUpper(char str[]) {
	int i;
	for (i = 0; str[i]; i++) {
		if (str[i] >= 'a' && str[i] <= 'z') {
			printf("%c", str[i] - 32);
		}
		else {
			printf("%c", str[i]);
		}
	}
	printf("\n");
}

void conLower(char str[]) {
	int i;
	for (i = 0; str[i]; i++) {
		if (str[i] >= 'A' && str[i] <= 'Z') {
			printf("%c", str[i] + 32);
		}
		else {
			printf("%c", str[i]);
		}
	}
	printf("\n");
}

void line(void) {
	printf("----------------------------------------------\n");
}