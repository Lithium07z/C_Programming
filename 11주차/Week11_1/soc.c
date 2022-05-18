#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void fun1(void) {
	int i;

	struct student {
		char name[20];
		int korean, english, math;
		double average;

	};

	struct student s1 = { "김준호", 100, 100, 100, 0.0 }; // 구조체의 초기화 
	struct student s2 = s1; // 구조체 끼리의 대입은 가능하나 비교는 불가능
	
	printf("s1 구조체의 이름 : %s\n", s1.name);
	printf("s1 구조체를 대입한 s2 구조체의 이름 : %s\n", s2.name);

	if (s1.average == s2.average) { // 구조체의 멤버 대 멤버로 비교해야 함 
		printf("두 평균이 일치합니다.\n");
	}

	struct student arr[3]; // 구조체 배열 
	
	for (i = 0; i < sizeof(arr) / sizeof(arr[0]); i++) {
		printf("이름 : ");
		scanf("%s", &arr[i].name);
		printf("국어점수 : ");
		scanf("%d", &arr[i].korean);
		printf("영어점수 : ");
		scanf("%d", &arr[i].english);
		printf("수학점수 : ");
		scanf("%d", &arr[i].math);
		fflush(stdin);
	}

	
	for (i = 0; i < sizeof(arr) / sizeof(arr[0]); i++) {
		arr[i].average = (double)(arr[i].korean + arr[i].english + arr[i].math) / 3;
		printf("이름 : %s  평균 : %f\n", arr[i].name,arr[i].average);
	}

	typedef struct student std;
	std s3 = {"Lukas", 100, 90, 80, 90.0};
	std* p = &s3;
	printf("%s의 평균은 %f입니다.\n", p -> name, p -> average);

	struct time {
		unsigned int sec : 6;
	} t1;
	t1.sec = 70;
	printf("구조체 time의 sec : %d\n", t1.sec);
	// sec에 할당된 비트는 6비트이므로 2의6승까지 즉, 0 ~ 63까지 표현할 수 있다. 
	// 따라서 70을 넣으면 오버플로우가 발생, 70 - 64 = 6로 6이 출력된다. 
}

void fun2(void) {
	typedef struct person { // typedef를 사용
		char name[20];
		char sex;
		int job_code;
		union { // 공용체 선언
			char company_name[20];
			char school_name[20]; // company_name과 메모리 공유
		} job_info;
	} PERSON; // PERSON을 데이터 형으로 사용 가능, struct 키워드 필요 X
	PERSON p1 = {"김준호", 'M', 0, "hallym"};
	printf("%s\n", p1.job_info.school_name);
	printf("%s\n", p1.job_info.company_name);
	// 두 변수 모두 같은 메모리를 참조하므로 같은 값이 출력됨
	
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

	printf("구조체의 크기 : %d\n", sizeof(t1)); 
	/* 가장 큰 자료형 크기의 배수로 정렬함 따라서 t1을 기준으로 예시를 든다면
	*  가장 큰 자료형 = double 이므로 double의 배수 16으로 초기화됨
	*  정렬하며 남는 공간을 채우는 것을 패딩(padding)이라 함
	*  char + int + [남는 공간3] + double = 16
	*/
	printf("공용체의 크기 : %d\n", sizeof(t2));
}

void fun3(void) {
	enum week {sun = 6, mon = 0, tue = 1, wed = 2, thu = 3, fri = 4, sat = 5}; // 열거체 내부의 값들을 열거 상수라 한다.
	// 내부의 값들은 정수형 상수로 처리한다. 내부적으로 처음 0인덱스부터 1, 2....n
	enum week weekday; // 열거체 변수
	weekday = sun; // 열거체 변수에 열거체의 sun에 해당하는 값 저장
	printf("%d\n", weekday); // 열거체 변수 값 출력
}