#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void fun1() {
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j <= i; j++) {
			printf("#");
		}
		printf("\n");
	}
}

void fun2() {
	int arr[] = { 90, 100, -5, 65, 34, 20, 15, 7, 10, 85 };
	int i;
	int j;
	for (i = 0; i < 9; i++) {
		for (j = i + 1; j < 10; j++) {
			if (arr[i] > arr[j]) {
				int temp = arr[i];
				arr[i] = arr[j];
				arr[j] = temp;
			}
		}
	} 
	for (int i = 0; i < 10; i++) {
		printf("%d ", arr[i]);
	}
	printf("\n");
}

void fun3() {
	int i, j;
	int arr[5];
	float sum = 0;
	for (i = 0; i < 5; i++) {
		printf("[%d] ��° ������ �Է�:", i + 1);
		scanf("%d", &arr[i]);
	}
	printf("�Էµ� ������:");
	for (j = 0; j < 5; j++) {
		printf("%d ", arr[j]);
		sum += arr[j];
	}
	float avg = sum / 5;
	printf("\n����[%d]", (int)sum);
	printf("\n���[%.2f]", avg);
	if (avg <= 100 && avg >= 90) {
		printf("\n����[A]");
	}
	else if (avg < 90 && avg >= 80) {
		printf("\n����[B]");
	}
	else if (avg < 80 && avg >= 70) {
		printf("\n����[C]");
	}
	else if (avg < 70 && avg >= 80) {
		printf("\n����[D]");
	}
	else {
		printf("\n����[F]");
	}
}

int eSum(int arr[], int value) {
	int i; // �ݺ��� ����
	int sum = 0; // ���� ������ų ����
	for (i = 0; i < value; i++) {
		sum += arr[i];
	}
	return sum;
}