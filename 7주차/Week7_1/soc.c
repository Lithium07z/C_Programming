#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void swap(int arr[]) {
	int temp = arr[0];
	arr[0] = arr[1];
	arr[1] = temp;
}

void swapMain() {
	int arr[2];
	
	printf("�� ���� ���� ���� �Է��ϼ��� : ");
	scanf("%d", &arr[0]);
	scanf("%d", &arr[1]);
	printf("���� x = [%d], y= [%d]�� �Է� �޾�\n", arr[0], arr[1]);
	printf("swap()�Լ� ���� ��\n");
	swap(arr);
	printf("x = [%d],  y= [%d]�� ��ȯ�Ǿ����ϴ�.\n", arr[0], arr[1]);
}

void reverse() {
	char arr[20];
	int i, j;
	int count = 0;
	int minus = 1;
	
	printf("���ڿ��� �Է��ϼ��� : ");
	scanf("%s", &arr);

	for (i = 0; i < arr[i]; i++) { // str[i]�� null�̸� �ݺ����� Ż�����״�
		count++; // count�Ǵ� ������ null�� �ƴ϶� �����ϴ� ������ ������ ��
	}
	for (i = count - 1; i >= 0; i--) { // �ε����� ����Ϸ��� ũ�� - 1�̾���ϴ� count - 1
		for (j = count - minus; j >= 0; j--) { // minus�� ��ŭ �ݺ��ؼ� ���
			printf("%c", arr[j]);
		}
		printf("\n");
		minus++; // minus�� �������Ѽ� ���� �ݺ����� ��ĭ �� ����ϰ� ���� 
	}
	printf("\n");
}

void array() {
	int menu;
	int i, j;
	int four = 4;

	while (1) {
		int arr[20];
		int count = 0;

		printf("1) �� �켱 ������ ������ ���\n2) �� �켱 ������ ������ ���\n3) ���α׷� ���� \n��ȣ�� �����ϼ��� : ");
		scanf("%d", &menu);
		if (menu == 1) {
			for (i = 1; i <= 20; i++) {
				arr[i - 1] = i;
				printf("%3d", arr[i - 1]);
				if (i % 5 == 0) {
					printf("\n");
				}
			}
			printf("\n");
		}
		else if (menu == 2) { // �� �켱 ����
			for (i = 1; i <= 4; i++) { 
				for (j = 0; j < 5; j++) {
					if (count % 5 == 0) { // count�� 5�� ��� ���� �� ���ڸ� �̹Ƿ�
						arr[count] = i; // i�� �� �� �ֵ��� ��
						count++; // �׸��� ���� �ε�����
						continue;
					}
					arr[count] = i + four; // �� �켱 ������ ���� �� ������ ���� ���� ù��° ������ 4�� ������Ŵ
					four += 4; // 4����
					count++; // ���� �ε����� 
				}
				four = 4; // �ϳ� �� ������ ���� ������ 
			}
			for (int i = 0; i < 20; i++) {
				printf("%3d", arr[i]);
				if (i % 5 == 4) {
					printf("\n");
				}
			}
		}
		else if (menu == 3) {
			break;
		}
		else {
			printf("�ش� ��ȣ�� �޴��� �����ϴ�.");
		}
	}
}