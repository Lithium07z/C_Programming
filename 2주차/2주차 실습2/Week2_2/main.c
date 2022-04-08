#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>

int main(void) {
	char str[127];
	printf("문자열을 입력하세요 : ");
	scanf("%[^\n]s", str);
	int upper = 0;
	int lower = 0;
	int cnt;
	for (cnt = 0; str[cnt]; cnt++);
	for (int i = 0; i < cnt; i++) {
		if (str[i] >= 65 && str[i] <= 90) {
			upper += 1;
		}
		else if (str[i] >= 97 && str[i] <= 122) {
			lower += 1;
		}
	}
	printf("문자열의 길이는 %d바이트 입니다.\n", cnt);
	printf("대문자의 개수는 %d이고.\n", upper);
	printf("소문자의 개수는 %d입니다.\n", lower);
}