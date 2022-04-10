#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

static char he[5]; // static이라 실행 전에 메모리에 할당되면서 초기화됨, 전역변수임 
void array1(void) {
	he[0] = 'h'; // 전역변수에 넣기 때문에 함수가 종료되도 사라지지 않음  
	he[1] = 'e';
	he[2] = 'l';
	he[3] = 'l';
	he[4] = 'o';
}

void efun1(void) {
	int i;

	array1(); // array1 함수 호출
	for (i = 0; i < 5; i++) {
		printf("he[%d] = %c\n", i, he[i]);
	}
}

void array2(char he[]) { // 매개변수로 static 문자 배열을 받음 
	he[0] = 'h'; // 매개변수로 받은 static 문자 배열에 값을 넣음 
	he[1] = 'e'; 
	he[2] = 'l'; 
	he[3] = 'l';
	he[4] = 'o';
}

void efun2(void) {
	static char he[5]; // static타입 배열
	int i;

	array2(he); // array2함수에 he배열을 넘김 
	for (i = 0; i < 5; i++) {
		printf("he[%d] = %c\n", i, he[i]);
	}
}

void array3(char he[]) {
	int i;
	char temp; // 엔터 값을 저장할 임시변수

	i = 0;
	do {
		printf("he[%d] :", i);
		scanf_s("%c%c", &he[i], 1, &temp, 1);
		// 문자 입력 후 엔터까지 문자로 인식하기 때문에 엔터는 temp에 저장해 배열에 원치않는 값이 들어가는 것을 방지
	} while (++i < 5);
}

void efun3(void) {
	char he[5]; // 입력값을 저장할 배열
	int i;

	array3(he); // array3함수에 he 배열을 넘김
	printf("\n[출력결과]\n");
	for (i = 0; i < 5; i++) {
		printf("he[%d] = %c\n", i, he[i]);
	}
}

void array4(char he[]) {
	int i = 0;
	do {
		printf("he[%d] :", i);
		he[i] = getchar(); // getchar()함수로 문자를 입력받음
		//fflush(stdin); < 인지가 될 때도 안될 때도 있음, 표준입력 장치로 부터 들어오는 임시버퍼를 비우는 함수
		getchar(); // 엔터값은 getchar()로 받되 저장하지 않고 넘김
	} while (++i < 5);
}

void efun4(void) {
	char he[5]; // 입력값을 저장할 배열
	int i;

	array4(he); // array4함수에 he 배열을 넘김
	printf("\n[출력결과]\n");
	for (i = 0; i < 5; i++) {
		printf("he[%d] = %c\n", i, he[i]);
	}
}

void array5(char he[]) {
	printf("문자열을 입력하세요 : ");
	gets(he); // 문자열을 입력받는 함수 array4의 로직과 같음
}

void efun5(void) {
	char he[5]; // 입력값을 저장할 배열
	int i;

	array5(he); // array5함수에 he 배열을 넘김
	printf("\n[출력결과]\n");
	for (i = 0; i < 5; i++) {
		printf("he[%d] = %c\n", i, he[i]);
	}
}

void array6(char str1[], char str2[]) {
	char tmp;
	int i = 0, size;

	size = sizeof(str1); // char는 1바이트라 sizeof가 곧 문자열 길이
	
	do {
		tmp = str1[i]; // str[i] 번째 값을 tmp에 임시저장
		str1[i] = str2[i]; // str2[i] 값을 str1[i]에 덮어씌우기
		str2[i] = tmp; // str2[1]에 str[i]값을 가진 tmp를 덮어 씌우기
	} while (++i < size);
}

void efun6(void) {
	char str1[] = "ABCD";
	char str2[] = "1234";

	printf("[교체 전 출력결과] \n");
	printf("str1 = %s, str2 = %s\n", str1, str2);

	array6(str1, str2); // array6함수에서 두 문자열의 값이 바뀜 

	printf("[교체 후 출력결과] \n");
	printf("str1 = %s, str2 = %s\n", str1, str2);
}

void array7pnt(char str[]) { // str주소를 받음
	printf("%s\n", str); // 받은 주소의 위치부터 배열 값을 출력
}

void efun7(void) {
	char str[] = "ABCDE";
	int i;

	for (i = 0; i < sizeof(str) - 1; i++) { 
		// 문자열 뒤에 null 있기 때문에 sizeof(str)의 값은 6이므로 -1을 해야함
		array7pnt(&str[i]); // str의 i번째 인덱스의 주소를 array7pnt로 보냄 
	}
}

void efun8(void) {
	char str[] = "ABCDE";
	int i;

	for (i = sizeof(str) - 2; i >= 0; i--) {
		// 문자열 뒤에 null이 있기 때문에 sizeof(str)의 값은 6이므로 -2를 해야함
		array7pnt(&str[i]);
	}
} 

