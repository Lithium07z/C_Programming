#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void fun1(void) {
	int i;

	struct student {
		char name[20];
		int korean, english, math;
		double average;

	};

	struct student s1 = { "����ȣ", 100, 100, 100, 0.0 }; // ����ü�� �ʱ�ȭ 
	struct student s2 = s1; // ����ü ������ ������ �����ϳ� �񱳴� �Ұ���
	
	printf("s1 ����ü�� �̸� : %s\n", s1.name);
	printf("s1 ����ü�� ������ s2 ����ü�� �̸� : %s\n", s2.name);

	if (s1.average == s2.average) { // ����ü�� ��� �� ����� ���ؾ� �� 
		printf("�� ����� ��ġ�մϴ�.\n");
	}

	struct student arr[3]; // ����ü �迭 
	
	for (i = 0; i < sizeof(arr) / sizeof(arr[0]); i++) {
		printf("�̸� : ");
		scanf("%s", &arr[i].name);
		printf("�������� : ");
		scanf("%d", &arr[i].korean);
		printf("�������� : ");
		scanf("%d", &arr[i].english);
		printf("�������� : ");
		scanf("%d", &arr[i].math);
		fflush(stdin);
	}

	
	for (i = 0; i < sizeof(arr) / sizeof(arr[0]); i++) {
		arr[i].average = (double)(arr[i].korean + arr[i].english + arr[i].math) / 3;
		printf("�̸� : %s  ��� : %f\n", arr[i].name,arr[i].average);
	}

	typedef struct student std;
	std s3 = {"Lukas", 100, 90, 80, 90.0};
	std* p = &s3;
	printf("%s�� ����� %f�Դϴ�.\n", p -> name, p -> average);

	struct time {
		unsigned int sec : 6;
	} t1;
	t1.sec = 70;
	printf("����ü time�� sec : %d\n", t1.sec);
	// sec�� �Ҵ�� ��Ʈ�� 6��Ʈ�̹Ƿ� 2��6�±��� ��, 0 ~ 63���� ǥ���� �� �ִ�. 
	// ���� 70�� ������ �����÷ο찡 �߻�, 70 - 64 = 6�� 6�� ��µȴ�. 
}

void fun2(void) {
	typedef struct person { // typedef�� ���
		char name[20];
		char sex;
		int job_code;
		union { // ����ü ����
			char company_name[20];
			char school_name[20]; // company_name�� �޸� ����
		} job_info;
	} PERSON; // PERSON�� ������ ������ ��� ����, struct Ű���� �ʿ� X
	PERSON p1 = {"����ȣ", 'M', 0, "hallym"};
	printf("%s\n", p1.job_info.school_name);
	printf("%s\n", p1.job_info.company_name);
	// �� ���� ��� ���� �޸𸮸� �����ϹǷ� ���� ���� ��µ�
	
	struct test1 {
		char ch;
		int n;
		double d;
	} t1;

	union test2 {
		char ch;
		int n;
		double d;
	} t2;

	printf("����ü�� ũ�� : %d\n", sizeof(t1)); 
	/* ���� ū �ڷ��� ũ���� ����� ������ ���� t1�� �������� ���ø� ��ٸ�
	*  ���� ū �ڷ��� = double �̹Ƿ� double�� ��� 16���� �ʱ�ȭ��
	*  �����ϸ� ���� ������ ä��� ���� �е�(padding)�̶� ��
	*  char + int + [���� ����3] + double = 16
	*/
	printf("����ü�� ũ�� : %d\n", sizeof(t2));
}

void fun3(void) {
	enum week {sun = 6, mon = 0, tue = 1, wed = 2, thu = 3, fri = 4, sat = 5}; // ����ü ������ ������ ���� ����� �Ѵ�.
	// ������ ������ ������ ����� ó���Ѵ�. ���������� ó�� 0�ε������� 1, 2....n
	enum week weekday; // ����ü ����
	weekday = sun; // ����ü ������ ����ü�� sun�� �ش��ϴ� �� ����
	printf("%d\n", weekday); // ����ü ���� �� ���
}