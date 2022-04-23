#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void swap(int arr[]) {
	int temp = arr[0];
	arr[0] = arr[1];
	arr[1] = temp;
}

void swapMain() {
	int arr[2];
	
	printf("두 개의 정수 값을 입력하세요 : ");
	scanf("%d", &arr[0]);
	scanf("%d", &arr[1]);
	printf("정수 x = [%d], y= [%d]를 입력 받아\n", arr[0], arr[1]);
	printf("swap()함수 수행 후\n");
	swap(arr);
	printf("x = [%d],  y= [%d]로 교환되었습니다.\n", arr[0], arr[1]);
}

void reverse() {
	char arr[20];
	int i, j;
	int count = 0;
	int minus = 1;
	
	printf("문자열을 입력하세요 : ");
	scanf("%s", &arr);

	for (i = 0; i < arr[i]; i++) { // str[i]가 null이면 반복문을 탈출할테니
		count++; // count되는 값들은 null이 아니라 실제하는 데이터 갯수를 셈
	}
	for (i = count - 1; i >= 0; i--) { // 인덱스로 사용하려면 크기 - 1이어야하니 count - 1
		for (j = count - minus; j >= 0; j--) { // minus뺀 만큼 반복해서 출력
			printf("%c", arr[j]);
		}
		printf("\n");
		minus++; // minus를 증가시켜서 다음 반복문때 한칸 덜 출력하게 만듬 
	}
	printf("\n");
}

void array() {
	int menu;
	int i, j;
	int four = 4;

	while (1) {
		int arr[20];
		int count = 0;

		printf("1) 행 우선 순서로 데이터 출력\n2) 열 우선 순서로 데이터 출력\n3) 프로그램 종료 \n번호를 선택하세요 : ");
		scanf("%d", &menu);
		if (menu == 1) {
			for (i = 1; i <= 20; i++) {
				arr[i - 1] = i;
				printf("%3d", arr[i - 1]);
				if (i % 5 == 0) {
					printf("\n");
				}
			}
			printf("\n");
		}
		else if (menu == 2) { // 열 우선 순서
			for (i = 1; i <= 4; i++) { 
				for (j = 0; j < 5; j++) {
					if (count % 5 == 0) { // count가 5인 경우 행의 맨 앞자리 이므로
						arr[count] = i; // i가 들어갈 수 있도록 함
						count++; // 그리고 다음 인덱스로
						continue;
					}
					arr[count] = i + four; // 열 우선 순서로 정렬 후 행으로 보면 행의 첫번째 값부터 4씩 누적시킴
					four += 4; // 4누적
					count++; // 다음 인덱스로 
				}
				four = 4; // 하나 행 끝나면 다음 행으로 
			}
			for (int i = 0; i < 20; i++) {
				printf("%3d", arr[i]);
				if (i % 5 == 4) {
					printf("\n");
				}
			}
		}
		else if (menu == 3) {
			break;
		}
		else {
			printf("해당 번호의 메뉴가 없습니다.");
		}
	}
}