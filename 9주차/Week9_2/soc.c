#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void fun1(void) {
	int i, j, k = 0; 
	int l = 6;
	int arrA[2][3];
	int arrB[2][3]; 
	int arrR[2][3]; // arrA�� arrB�� ���� 2A - 3B������ �� ������ �迭 
	int arrS[12]; // arrA�� arrB�� ���� ��� ������ �����ϱ� ���� �迭

	for (i = 0; i < 2; i++) { // arrA�� �� �߰�
		for (j = 0; j < 3; j++) {
			printf("Input to Array A[%d][%d] : ", i, j);
			scanf("%d", &arrA[i][j]);
		}
	}
	for (i = 0; i < 2; i++) { // arrB�� �� �߰�
		for (j = 0; j < 3; j++) {
			printf("Input to Array B[%d][%d] : ", i, j);
			scanf("%d", &arrB[i][j]);
		}
	}
	for (i = 0; i < 2; i++) { // arrR�� 2A - 3B�� �߰� 
		for (j = 0; j < 3; j++) {
			arrR[i][j] = 2 * arrA[i][j] - 3 * arrB[i][j];
		}
	}
	printf("\n[��°��]\n");
	for (i = 0; i < 2; i++) { // 2A - 3B ��� 
		for (j = 0; j < 3; j++) {
			printf("%3d ", arrR[i][j]);
		}
		printf("\n");
	}
	for (i = 0; i < 2; i++) { // arrA�� arrB�� ��ģ ũ���� �迭 arrS�� A�� ���� �߰� 
		for (j = 0; j < 3; j++) {
			arrS[k] = arrA[i][j];
			arrS[l] = arrB[i][j];
			k++;
			l++;
		}
	}
	for (i = 0; i < 2; i++) { // arrA�� arrB�� ��ģ ũ���� �迭 arrS�� B�� ���� �߰� 
		for (j = 0; j < 3; j++) {
			arrS[k] = arrB[i][j];
			k++;
		}
	}
	for (i = 0; i < sizeof(arrS) / sizeof(arrS[0]) - 1; i++) { // �� �迭 arrA�� arrB�� ���� ��� ���� arrS�� ������ 
		for (j = i + 1; j < sizeof(arrS) / sizeof(arrS[0]); j++) {
			if (arrS[i] > arrS[j]) {
				int temp = arrS[i];
				arrS[i] = arrS[j];
				arrS[j] = temp;
			}
		}
	}
	printf("\n[��°��]\n");
	printf("�� �迭 A�� B�� �������� ��� : "); // ���������� ���ĵ� �迭 arrS ��� 
	for (i = 0; i < 12; i++) {
		printf("%d ", arrS[i]);
	}
	printf("\n");
}
