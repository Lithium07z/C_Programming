#include <stdio.h>

void nArr(char *arr); // 함수 원형 선언 
void bArr(char *arr, int size); // 함수 원형 선언
void sArr(char *arr, int size); // 함수 원형 선언 

void fun1(void) {
	char arr[20];
	int menu;
	int size = 0;
	int i;
	char (*fpt[])(char arr[]) = {nArr, bArr, sArr}; // 선언과 동시에 초기화

	printf("문자열을 입력하세요 : ");
	gets(arr); // 공백 포함해서 받아야 하니까 gets로 입력받음
	for (i = 0; arr[i]; i++) {
		size++; // 사이즈 계산 
	}

	// char (*fpt[3])(char arr[]);
	//fpt[0] = nArr; // 하나씩 지정해줘도 됨
	//fpt[1] = bArr;
	//fpt[2] = sArr;

	while (1) {
		printf("1) 원본 문자열 출력\n");
		printf("2) 대문자로 문자열 출력\n");
		printf("3) 소문자로 문자열 출력\n");
		printf("4) 프로그램 종료\n");
		printf("출력 형식을 선택하세요 : ");
		scanf_s("%d", &menu, 1);

		switch (menu) {
			case 1:
				fpt[menu - 1](&arr); // 함수 포인터가 가리키는 menu - 1번째 함수에 문자열 배열 주소 넘기기  
				break;
			case 2:
				fpt[menu - 1](&arr, size);
				break;
			case 3:
				fpt[menu - 1](&arr, size);
				break;
			default:
				exit(); // 1, 2, 3메뉴 아니면 프로그램 종료 
		}
	}
}

void nArr(char *arr) { // 문자열 주소 받음 
	printf("%s\n", arr); // 주소 위치 값 그대로 출력 
}

void bArr(char *arr, int size) { // 문자열 주소, 문자열 길이 받음 
	int i;
	for (i = 0; i < size; i++) {
		if (*(arr + i) >= 97 && *(arr + i) <= 122) { // 주소 + i번째 값이 소문자면 
			*(arr + i) = *(arr + i) - 32; // 대문자로 바꿈
		}
	}
	printf("%s\n", arr);
}

void sArr(char *arr, int size) {
	int i;
	for (i = 0; i < size; i++) {
		if (*(arr + i) >= 65 && *(arr + i) <= 90) { // 주소 + i번째 값이 대문자면
			*(arr + i) = *(arr + i) + 32; // 소문자로 바꿈 
		}
	}
	printf("%s\n", arr);
}

void printOut(char* menu);

void fun2() {
	char* menu[] = { "New Game", "Load Game", "2 Play", "Option", "Exit" };
	char (*fpt)(char** menu) = printOut; // 선언과 동시에 초기화, 포인터 배열이므로 이중 포인터를 받는 함수를 가리키게함
	//char (*fpt)(char *menu[]);
	//fpt = printOut; < 이렇게 나눠서해도 됨 
	fpt(&menu);

}

void printOut(char** menu) { // 포인터 배열의 시작주소 값 받음 
	int i, j;
	int size = 0;
	for (i = 0; *(menu + i); i++) { // 시작 주소 값 부터 차례로 문자열 출력, 주소 값이 menu를 넘어가면 종료 
		printf("[%s] 문자열의 개수는", *(menu + i));
		for (j = 0; *(*(menu + i) + j); j++) { // 해당 주소 값 내부의 문자를 가져온뒤 주소를 증가시키며 반복
			size++; // 사이즈 증가 
		}
		printf("[%d]byte입니다.\n", size);
		size = 0;
	}
}