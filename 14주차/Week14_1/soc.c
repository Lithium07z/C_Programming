#include <stdio.h>
#define _CRT_SECURE_NO_WARNINGS

struct student {
	int num;
	double grade;
};

typedef struct student STN;
void print_data(STN* ps) {
	printf("학번 : %d\n", ps -> num);
	printf("학점 : %.1f\n", ps -> grade);
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
	printf("입력하신 데이터는\n");
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
	printf("몇 개의 정수를 입력하시겠습니까? ");
	scanf_s("%d", &len);
	printf("[%d]개의 정수를 입력하세요 : ", len);
	int* arr = NULL;
	arr = malloc(sizeof(int) * len);
	for (i = 0; i < len; i++) {
		scanf_s("%d", &arr[i]);
	}

	printArray(arr, len);
	sum = eSum(arr, len); // 입력한 배열, 개수
	PRN1(sum);
	avg = eAvg(arr, len);
	PRN2(avg);
	
	return 0;
}