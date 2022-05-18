#include <stdio.h>

void nArr(char *arr); // �Լ� ���� ���� 
void bArr(char *arr, int size); // �Լ� ���� ����
void sArr(char *arr, int size); // �Լ� ���� ���� 

void fun1(void) {
	char arr[20];
	int menu;
	int size = 0;
	int i;
	char (*fpt[])(char arr[]) = {nArr, bArr, sArr}; // ����� ���ÿ� �ʱ�ȭ

	printf("���ڿ��� �Է��ϼ��� : ");
	gets(arr); // ���� �����ؼ� �޾ƾ� �ϴϱ� gets�� �Է¹���
	for (i = 0; arr[i]; i++) {
		size++; // ������ ��� 
	}

	// char (*fpt[3])(char arr[]);
	//fpt[0] = nArr; // �ϳ��� �������൵ ��
	//fpt[1] = bArr;
	//fpt[2] = sArr;

	while (1) {
		printf("1) ���� ���ڿ� ���\n");
		printf("2) �빮�ڷ� ���ڿ� ���\n");
		printf("3) �ҹ��ڷ� ���ڿ� ���\n");
		printf("4) ���α׷� ����\n");
		printf("��� ������ �����ϼ��� : ");
		scanf_s("%d", &menu, 1);

		switch (menu) {
			case 1:
				fpt[menu - 1](&arr); // �Լ� �����Ͱ� ����Ű�� menu - 1��° �Լ��� ���ڿ� �迭 �ּ� �ѱ��  
				break;
			case 2:
				fpt[menu - 1](&arr, size);
				break;
			case 3:
				fpt[menu - 1](&arr, size);
				break;
			default:
				exit(); // 1, 2, 3�޴� �ƴϸ� ���α׷� ���� 
		}
	}
}

void nArr(char *arr) { // ���ڿ� �ּ� ���� 
	printf("%s\n", arr); // �ּ� ��ġ �� �״�� ��� 
}

void bArr(char *arr, int size) { // ���ڿ� �ּ�, ���ڿ� ���� ���� 
	int i;
	for (i = 0; i < size; i++) {
		if (*(arr + i) >= 97 && *(arr + i) <= 122) { // �ּ� + i��° ���� �ҹ��ڸ� 
			*(arr + i) = *(arr + i) - 32; // �빮�ڷ� �ٲ�
		}
	}
	printf("%s\n", arr);
}

void sArr(char *arr, int size) {
	int i;
	for (i = 0; i < size; i++) {
		if (*(arr + i) >= 65 && *(arr + i) <= 90) { // �ּ� + i��° ���� �빮�ڸ�
			*(arr + i) = *(arr + i) + 32; // �ҹ��ڷ� �ٲ� 
		}
	}
	printf("%s\n", arr);
}

void printOut(char* menu);

void fun2() {
	char* menu[] = { "New Game", "Load Game", "2 Play", "Option", "Exit" };
	char (*fpt)(char** menu) = printOut; // ����� ���ÿ� �ʱ�ȭ, ������ �迭�̹Ƿ� ���� �����͸� �޴� �Լ��� ����Ű����
	//char (*fpt)(char *menu[]);
	//fpt = printOut; < �̷��� �������ص� �� 
	fpt(&menu);

}

void printOut(char** menu) { // ������ �迭�� �����ּ� �� ���� 
	int i, j;
	int size = 0;
	for (i = 0; *(menu + i); i++) { // ���� �ּ� �� ���� ���ʷ� ���ڿ� ���, �ּ� ���� menu�� �Ѿ�� ���� 
		printf("[%s] ���ڿ��� ������", *(menu + i));
		for (j = 0; *(*(menu + i) + j); j++) { // �ش� �ּ� �� ������ ���ڸ� �����µ� �ּҸ� ������Ű�� �ݺ�
			size++; // ������ ���� 
		}
		printf("[%d]byte�Դϴ�.\n", size);
		size = 0;
	}
}