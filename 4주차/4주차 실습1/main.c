#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void main(void)
{
	int arr[5];
	for (int i = 0; i < 5; i++) {
		printf("[%d]������ : ", i);
		scanf("%d", &arr[i]);
	}
	printf("�Է��� �����ʹ� ");
	for (int i = 0; i < 5; i++) {
		printf("%d", arr[i]);
		if (i != 4) {
			printf(",");
		}
	}
	printf(" �Դϴ�. \n");
}