#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void fun1(void) {
	char arr[] = "This is A Sample.";
	char* p;
	p = arr;
	int menu, i;

	while (1) {
		printf("1) ���� ���ڿ� ���\n");
		printf("2) �빮�ڷ� ���ڿ� ���\n");
		printf("3) �ҹ��ڷ� ���ڿ� ���\n");
		printf("4) ���α׷� ����\n");
		printf("��������� �����ϼ��� : ");
		scanf("%d", &menu);

		if (menu == 1) {
			printf("%s\n", p);
		} else if (menu == 2) {
			for (i = 0; i < sizeof(arr) / sizeof(arr[0]); i++) {
				if (*(p + i) >= 97 && *(p + i) <= 122) {
					*(p + i) = *(p + i) - 32;
				}
			}
			printf("%s\n", p);
		} else if (menu == 3) {
			for (i = 0; i < sizeof(arr) / sizeof(arr[0]); i++) {
				if (*(p + i) >= 65 && *(p + i) <= 90) {
					*(p + i) = *(p + i) + 32;
				}
			}
			printf("%s\n", p);
		} else {
			break;
		}
	}
}

void fun2(void) {
	char arr[20];
	char* p;
	p = arr;
	int i;
	int acnt = 0;
	int bcnt = 0;
	int scnt = 0;

	printf("���ڿ��� �Է��ϼ��� : ");
	gets(arr);

	for (i = 0; i < arr[i]; i++) {
		if (*(p + i) >= 97 && *(p + i) <= 122) {
			scnt++;
		}
		else if (*(p + i) >= 65 && *(p + i) <= 90) {
			bcnt++;
		}
		acnt++;
	}
	printf("��ü ���ڿ��ǰ��� : %d\n", acnt);
	printf("�빮���� ���� : %d\n", bcnt);
	printf("�ҹ����� ���� : %d\n", scnt);
}

void fun3(char *address) {
	int i = 0;
	int cnt = 0;
	
	printf("�Էµ� ���ڿ��� ");
	for (i = 0; i < *(address + i); i++) {
		printf("%c", *(address + i));
		cnt++;
	}
	printf("�� ��ü ���ڿ��� ������ %d �Դϴ�.\n", cnt);
}

void fun3_main(void) {
	char arr[20];
	char* p;
	p = arr;
	printf("���ڿ��� �Է��ϼ��� : ");
	gets(arr);
	fun3(p);
}