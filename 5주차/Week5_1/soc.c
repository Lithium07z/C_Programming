#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void fun1(void) {
		int count = 0; // 갯수 카운트
		int sum = 0; // 총합
		int i = 1; // 반복연산
		for (; i <= 100; i++) { // 1부터 100까지
			if (i % 5 == 0) { // 5의 배수만 
				printf("%d ", i); // 출력
				count++; // 갯수 증가
				sum += i; // 총합에 i값 누적
				if (count % 10 == 0) { // 10개 단위로 끊어서 출력
					printf("\n"); // 줄 바꿈 
				}
			}
		}
		printf("갯수: %d \n총합: %d\n", count, sum);
}

void fun2(int strt, int end, int ip) {
	int count = 0; // 갯수 카운트
	int sum = 0; // 총합 
	
	while (strt <= end) { // strt 부터 end 까지 반복
		if (strt % ip == 0) { // strt를 ip로 나눴을 때 0되는 값만 출력 (배수 출력)
			printf("%d ", strt);
			count++;
			sum += strt;
			if (count % 10 == 0) {
				printf("\n");
			}
		}
		strt++; // strt 증가
	}
	printf("\n갯수: %d \n총합: %d\n", count, sum);
	printf("--------------------------------\n");
}

void fun3(int cnt, char word) { // 함수 호출시 반복 횟수와 반복할 문자를 받음
	int i; // 반복연산
	for (i = 0; i < cnt; i++) { // 입력받은 횟수 만큼 반복연산
		printf("%c", word); // 출력
	}
	printf("\n");
}

void fun4(char str[]) { // 함수 호출시 문자열 받음 
	printf("%s\n", str); // 그대로 출력 
}

void conUpper(char str[]) {
	int i;
	for (i = 0; str[i]; i++) {
		if (str[i] >= 'a' && str[i] <= 'z') {
			printf("%c", str[i] - 32);
		}
		else {
			printf("%c", str[i]);
		}
	}
	printf("\n");
}

void conLower(char str[]) {
	int i;
	for (i = 0; str[i]; i++) {
		if (str[i] >= 'A' && str[i] <= 'Z') {
			printf("%c", str[i] + 32);
		}
		else {
			printf("%c", str[i]);
		}
	}
	printf("\n");
}

void line(void) {
	printf("----------------------------------------------\n");
}