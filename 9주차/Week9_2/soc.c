#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void fun1(void) {
	int i, j, k = 0; 
	int l = 6;
	int arrA[2][3];
	int arrB[2][3]; 
	int arrR[2][3]; // arrA와 arrB의 값을 2A - 3B연산한 뒤 저장할 배열 
	int arrS[12]; // arrA와 arrB의 값을 모두 저장해 정렬하기 위한 배열

	for (i = 0; i < 2; i++) { // arrA에 값 추가
		for (j = 0; j < 3; j++) {
			printf("Input to Array A[%d][%d] : ", i, j);
			scanf("%d", &arrA[i][j]);
		}
	}
	for (i = 0; i < 2; i++) { // arrB에 값 추가
		for (j = 0; j < 3; j++) {
			printf("Input to Array B[%d][%d] : ", i, j);
			scanf("%d", &arrB[i][j]);
		}
	}
	for (i = 0; i < 2; i++) { // arrR에 2A - 3B값 추가 
		for (j = 0; j < 3; j++) {
			arrR[i][j] = 2 * arrA[i][j] - 3 * arrB[i][j];
		}
	}
	printf("\n[출력결과]\n");
	for (i = 0; i < 2; i++) { // 2A - 3B 출력 
		for (j = 0; j < 3; j++) {
			printf("%3d ", arrR[i][j]);
		}
		printf("\n");
	}
	for (i = 0; i < 2; i++) { // arrA와 arrB를 합친 크기의 배열 arrS에 A의 값을 추가 
		for (j = 0; j < 3; j++) {
			arrS[k] = arrA[i][j];
			arrS[l] = arrB[i][j];
			k++;
			l++;
		}
	}
	for (i = 0; i < 2; i++) { // arrA와 arrB를 합친 크기의 배열 arrS에 B의 값을 추가 
		for (j = 0; j < 3; j++) {
			arrS[k] = arrB[i][j];
			k++;
		}
	}
	for (i = 0; i < sizeof(arrS) / sizeof(arrS[0]) - 1; i++) { // 두 배열 arrA와 arrB의 값을 모두 가진 arrS를 정렬함 
		for (j = i + 1; j < sizeof(arrS) / sizeof(arrS[0]); j++) {
			if (arrS[i] > arrS[j]) {
				int temp = arrS[i];
				arrS[i] = arrS[j];
				arrS[j] = temp;
			}
		}
	}
	printf("\n[출력결과]\n");
	printf("두 배열 A와 B의 오름차순 결과 : "); // 오름차순로 정렬된 배열 arrS 출력 
	for (i = 0; i < 12; i++) {
		printf("%d ", arrS[i]);
	}
	printf("\n");
}
