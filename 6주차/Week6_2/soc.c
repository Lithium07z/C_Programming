#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void dfun1(void) {
	char str[] = { 'H', 'e', 'l', 'l', 'o', 0};
	// str배열에 문자 하나씩 삽입, 마지막에 null값을 0으로 임의로 삽입해줌
	printf("입력된 문자열 : %s\n", str);
}

void dfun2(void) {
	char str[5];

	printf("문자열을 입력하세요 : ");
	scanf_s("%s", str, sizeof(str)); // scanf_s 사용으로 입력값에 있어서 오류를 줄임 sizeof(str)로 입력값의 크기를 지정
	printf("입력된 문자열 : %s\n", str);
}

void dfun3(char str[]) { // 매개변수로 받는 배열을 그대로 출력 
	printf("입력된 문자열 : %s\n", str);
}

char msg[] = "Hello";
void dfun4(char str[]) { // 전역변수 msg와 매개변수로 받는 배열을 그대로 출력
	printf("%s : %s\n", msg, str);
}

void dfun5(void) {
	int x, y, tmp;

	x = 10; 
	y = 20;
	printf("x = %d, y = %d\n", x, y); 

	tmp = x; // 임시변수에 x값 저장
	x = y; // x에 y값 저장 
	y = tmp; // y에 임시저장된 x 저장

	printf("x = %d, y = %d\n", x, y);
}

void dfun6(int x, int y) {
	int tmp;

	tmp = x; // 임시변수에 x값 저장
	x = y; // x에 y값 저장 
	y = tmp; // y에 임시저장된 x 저장
	// 실질적으로 교체는 되지만 그게 직접 반영되진 않음ㄱ
	printf("x = %d, y = %d\n", x, y); // 함수 내부에선 바뀌지만 main에서 실행시 안바뀜
}

void dfun7(int d[]) {
	int tmp;

	tmp = d[0]; // 배열 0번째 값을 임시변수에 저장 
	d[0] = d[1]; // 배열 1번째 값을 0번째에 저장
	d[1] = tmp; // 배열 1번째에 임시변수 값 저장

	printf("dfun7 :  x = %d, y = %d\n", d[0], d[1]);
}

void dfun7_main(void) {
	int arr[2];

	arr[0] = 10; 
	arr[1] = 20;

	printf("x = %d, y = %d\n", arr[0], arr[1]);

	dfun7(arr); // dfun7함수에 값을 교환할 두 값을 가진 배열을 넘겨줌

	printf("x = %d, y = %d\n", arr[0], arr[1]);
}

void dfun8(int arr[], int cnt) {
	int i, sum;

	sum = 0; // 배열 값을 누적합할 변수 
	for (i = 0; i < cnt; i++) {
		sum += arr[i]; // 배열값을 하나씩 꺼내서 누적합
	}

	printf("배열의 합은 %d 입니다.\n", sum);
}

void dfun8_main(void) {
	int data[] = { 10, 30, 15, 3, 100, 80, 9, 7 }; // 선언과 동시에 초기화
	int cnt;

	cnt = sizeof(data) / sizeof(data[0]); // 배열 전체 바이트 수를 배열 내 값 하나의 바이트로 나눠서 전체 크기 구함
	printf("배열의 크기는 %d \n", cnt);
	dfun8(data, cnt); // 배열이랑 배열 크기 넘겨줌
}

void dfun9(void) {
	char abc[3][9] = { "김은주", "김마리아", "소양" }; // 총 3개 한글은 2바이트라 김마리아가 4글자로 가장 기니까
	int i; // 8바이트 + null값 1바이트로 3행 9열의 2차원 배열을 생성해야함

	for (i = 0; i < 3; i++) {
		printf("%s %s\n", msg, abc[i]); // 앞서 위에 썼던 전역변수랑 같이 출력
	}
	printf("\n");
}