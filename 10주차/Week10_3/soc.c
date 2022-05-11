#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void fun1(void) {
	char arr[] = "This is A Sample.";
	char* p;
	p = arr;
	int menu, i;

	while (1) {
		printf("1) 원본 문자열 출력\n");
		printf("2) 대문자로 문자열 출력\n");
		printf("3) 소문자로 문자열 출력\n");
		printf("4) 프로그램 종료\n");
		printf("출력형식을 선택하세요 : ");
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

	printf("문자열을 입력하세요 : ");
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
	printf("전체 문자열의개수 : %d\n", acnt);
	printf("대문자의 개수 : %d\n", bcnt);
	printf("소문자의 개수 : %d\n", scnt);
}

void fun3(char *address) {
	int i = 0;
	int cnt = 0;
	
	printf("입력된 문자열은 ");
	for (i = 0; i < *(address + i); i++) {
		printf("%c", *(address + i));
		cnt++;
	}
	printf("로 전체 문자열의 개수는 %d 입니다.\n", cnt);
}

void fun3_main(void) {
	char arr[20];
	char* p;
	p = arr;
	printf("문자열을 입력하세요 : ");
	gets(arr);
	fun3(p);
}