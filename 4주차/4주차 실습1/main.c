#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void main(void)
{
	int arr[5];
	for (int i = 0; i < 5; i++) {
		printf("[%d]데이터 : ", i);
		scanf("%d", &arr[i]);
	}
	printf("입력한 데이터는 ");
	for (int i = 0; i < 5; i++) {
		printf("%d", arr[i]);
		if (i != 4) {
			printf(",");
		}
	}
	printf(" 입니다. \n");
}