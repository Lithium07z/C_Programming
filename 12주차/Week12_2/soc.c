#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

void fun1(void) {
	char temp[80];
	char* str[3];
	int i;
	
	for (i = 0; i < 3; i++) {
		printf("���ڿ��� �Է��ϼ��� : ");
		gets(temp);
		printf("���ڿ��� %s�̰�, ���̴� %d�Դϴ�.\n", temp, strlen(temp));
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

	printf("�й��� �Է��ϼ��� : ");
	scanf_s("%d%*c", &s.number);
	printf("�̸��� �Է��ϼ��� : ");
	gets(s.name);
	printf("������ �Է��ϼ��� : ");
	scanf_s("%f", &s.grade);

	printf("�й� : %d\n", s.number);
	printf("�̸� : %s\n", s.name);
	printf("���� : %.2f\n", s.grade);
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

	printf("�й� : %d\n", s.number);
	printf("�̸� : %s\n", s.name);
	printf("���� : %f\n", s.grade);
	printf("������� : %d�� %d�� %d��\n", s.dob->year, s.dob->month, s.dob->day);
}

void print_list(list);
struct address {
	char name[20];
	int age;
	char number[20];
	char location[20];
};
void fun4(void) {
	struct address list[5] = {        // ��Ұ� 5���� ����ü �迭 ����
		{"ȫ�浿", 23, "111 - 1111", "�︪�� ����"},
		{"�̼���", 35, "222 - 2222", "��õ ��õ��"},
		{"�庸��", 19, "333 - 3333", "�ϵ� û����"},
		{"������", 15, "444 - 4444", "�泲 õ��"},
		{"���߱�", 45, "555 - 5555", "Ȳ�ص� ����"}
	};
	print_list(list);       //����� ���� �Լ�
}

void print_list(struct address *list) {	
	int i;
	for (i = 0; i < 5; i++) {
		printf("%s\t%d\t%s\t%s\n", list[i].name, list[i].age, list[i].number, list[i].location);
	}
}