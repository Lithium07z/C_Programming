#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void)
{
	int arr[5];
	for (int i = 0; i < 5; i++) {
		printf("[%d]������ : ", i);
		scanf("%d", &arr[i]);
		if (arr[i] < 0 || arr[i] > 100) {
			printf("��ȿ���� ���� �������Դϴ�. �ٽ� �Է��ϼ���.\n");
			i--;
			continue;
		}
	}
	for (int i = 0; i < 5; i++) {
		printf("[%d] ", i);
		for (int j = 0; j < arr[i] / 10; j++) {
			printf("�� ");
		}
		printf("(%d)", arr[i]);
		printf("\n");
	}
}