#include <stdio.h>
#define _CRT_SECURE_NO_WARNINGS

struct student {
	int num;
	double grade;
};

typedef struct student STN;
void print_data(STN* ps) {
	printf("�й� : %d\n", ps -> num);
	printf("���� : %.1f\n", ps -> grade);
}

int fun1(void) {
	STN s1 = { 123, 4.5 };
	print_data(&s1);
	return 0;
}

#define PRN1(item) printf(#item" = [%d]\n", item);
#define PRN2(item) printf(#item" = [%.2f]\n", item);
void printArray(int *arr, int len) {
	int i;
	printf("�Է��Ͻ� �����ʹ�\n");
	for (i = 0; i < len; i++) {
		printf("[%d] : %d\n", i, *arr++);
	}
}

int eSum(int *arr, int len) {
	int sum = 0;
	int i;
	for (i = 0; i < len; i++) {
		sum += arr[i];
	}
	return sum;
}

double eAvg(int *arr, int len) {
	int avg;
	int i;
	avg = eSum(arr, len) / len;
	return avg;
}

int fun2(void) {
	int i;
	int len;
	int sum;
	double avg;
	printf("�� ���� ������ �Է��Ͻðڽ��ϱ�? ");
	scanf_s("%d", &len);
	printf("[%d]���� ������ �Է��ϼ��� : ", len);
	int* arr = NULL;
	arr = malloc(sizeof(int) * len);
	for (i = 0; i < len; i++) {
		scanf_s("%d", &arr[i]);
	}

	printArray(arr, len);
	sum = eSum(arr, len); // �Է��� �迭, ����
	PRN1(sum);
	avg = eAvg(arr, len);
	PRN2(avg);
	
	return 0;
}