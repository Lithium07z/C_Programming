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
		printf("[%d] 번째 데이터 입력:", i + 1);
		scanf("%d", &arr[i]);
	}
	printf("입력된 데이터:");
	for (j = 0; j < 5; j++) {
		printf("%d ", arr[j]);
		sum += arr[j];
	}
	float avg = sum / 5;
	printf("\n총합[%d]", (int)sum);
	printf("\n평균[%.2f]", avg);
	if (avg <= 100 && avg >= 90) {
		printf("\n학점[A]");
	}
	else if (avg < 90 && avg >= 80) {
		printf("\n학점[B]");
	}
	else if (avg < 80 && avg >= 70) {
		printf("\n학점[C]");
	}
	else if (avg < 70 && avg >= 80) {
		printf("\n학점[D]");
	}
	else {
		printf("\n학점[F]");
	}
}

int eSum(int arr[], int value) {
	int i; // 반복문 변수
	int sum = 0; // 총합 누적시킬 변수
	for (i = 0; i < value; i++) {
		sum += arr[i];
	}
	return sum;
}