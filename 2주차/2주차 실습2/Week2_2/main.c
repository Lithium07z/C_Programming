#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>

int main(void) {
	char str[127];
	printf("���ڿ��� �Է��ϼ��� : ");
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
	printf("���ڿ��� ���̴� %d����Ʈ �Դϴ�.\n", cnt);
	printf("�빮���� ������ %d�̰�.\n", upper);
	printf("�ҹ����� ������ %d�Դϴ�.\n", lower);
}