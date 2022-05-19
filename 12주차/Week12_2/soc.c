#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

void fun1(void) {
	char temp[80];
	char* str[3];
	int i;
	
	for (i = 0; i < 3; i++) {
		printf("문자열을 입력하세요 : ");
		gets(temp);
		printf("문자열은 %s이고, 길이는 %d입니다.\n", temp, strlen(temp));
		str[i] = (char*)malloc(strlen(temp) + 1);
		strcpy(str[i], temp);
	}
	
	printf("\n");
	for (i = 0; i < 3; i++) {
		printf("str[%d] : %s\n", i, str[i]);
	}

	for (i = 0; i < 3; i++) {
		free(str[i]);
	}
}

void fun2(void) {
	struct student {
		int number;
		char name[20];
		float grade;
	}s;

	printf("학번을 입력하세요 : ");
	scanf_s("%d%*c", &s.number);
	printf("이름을 입력하세요 : ");
	gets(s.name);
	printf("점수를 입력하세요 : ");
	scanf_s("%f", &s.grade);

	printf("학번 : %d\n", s.number);
	printf("이름 : %s\n", s.name);
	printf("점수 : %.2f\n", s.grade);
}

void fun3(void) {
	struct student {
		int number;
		char name[20];
		float grade;
		struct date {
			int year;
			int month;
			int day;
		};
		struct date* dob;
	};
	struct date d = { 11, 30, 2021 };
	struct student s = { 2020001, "Kim", 4.3 };

	s.dob = &d;

	printf("학번 : %d\n", s.number);
	printf("이름 : %s\n", s.name);
	printf("학점 : %f\n", s.grade);
	printf("생년월일 : %d년 %d월 %d일\n", s.dob->year, s.dob->month, s.dob->day);
}

void print_list(list);
struct address {
	char name[20];
	int age;
	char number[20];
	char location[20];
};
void fun4(void) {
	struct address list[5] = {        // 요소가 5개인 구조체 배열 선언
		{"홍길동", 23, "111 - 1111", "울릉도 독도"},
		{"이순신", 35, "222 - 2222", "춘천 옥천동"},
		{"장보고", 19, "333 - 3333", "완도 청해진"},
		{"유관순", 15, "444 - 4444", "충남 천안"},
		{"안중근", 45, "555 - 5555", "황해도 해주"}
	};
	print_list(list);       //사용자 정의 함수
}

void print_list(struct address *list) {	
	int i;
	for (i = 0; i < 5; i++) {
		printf("%s\t%d\t%s\t%s\n", list[i].name, list[i].age, list[i].number, list[i].location);
	}
}