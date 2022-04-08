#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

static char he[5]; // static�̶� ���� ���� �޸𸮿� �Ҵ�Ǹ鼭 �ʱ�ȭ��, ���������� 
void array1(void) {
	he[0] = 'h'; // ���������� �ֱ� ������ �Լ��� ����ǵ� ������� ����  
	he[1] = 'e';
	he[2] = 'l';
	he[3] = 'l';
	he[4] = 'o';
}

void efun1(void) {
	int i;

	array1(); // array1 �Լ� ȣ��
	for (i = 0; i < 5; i++) {
		printf("he[%d] = %c\n", i, he[i]);
	}
}

void array2(char he[]) { // �Ű������� static ���� �迭�� ���� 
	he[0] = 'h'; // �Ű������� ���� static ���� �迭�� ���� ���� 
	he[1] = 'e'; 
	he[2] = 'l'; 
	he[3] = 'l';
	he[4] = 'o';
}

void efun2(void) {
	static char he[5]; // staticŸ�� �迭
	int i;

	array2(he); // array2�Լ��� he�迭�� �ѱ� 
	for (i = 0; i < 5; i++) {
		printf("he[%d] = %c\n", i, he[i]);
	}
}

void array3(char he[]) {
	int i;
	char temp; // ���� ���� ������ �ӽú���

	i = 0;
	do {
		printf("he[%d] :", i);
		scanf_s("%c%c", &he[i], 1, &temp, 1);
		// ���� �Է� �� ���ͱ��� ���ڷ� �ν��ϱ� ������ ���ʹ� temp�� ������ �迭�� ��ġ�ʴ� ���� ���� ���� ����
	} while (++i < 5);
}

void efun3(void) {
	char he[5]; // �Է°��� ������ �迭
	int i;

	array3(he); // array3�Լ��� he �迭�� �ѱ�
	printf("\n[��°��]\n");
	for (i = 0; i < 5; i++) {
		printf("he[%d] = %c\n", i, he[i]);
	}
}

void array4(char he[]) {
	int i = 0;
	do {
		printf("he[%d] :", i);
		he[i] = getchar(); // getchar()�Լ��� ���ڸ� �Է¹���
		//fflush(stdin); < ������ �� ���� �ȵ� ���� ����, ǥ���Է� ��ġ�� ���� ������ �ӽù��۸� ���� �Լ�
		getchar(); // ���Ͱ��� getchar()�� �޵� �������� �ʰ� �ѱ�
	} while (++i < 5);
}

void efun4(void) {
	char he[5]; // �Է°��� ������ �迭
	int i;

	array4(he); // array4�Լ��� he �迭�� �ѱ�
	printf("\n[��°��]\n");
	for (i = 0; i < 5; i++) {
		printf("he[%d] = %c\n", i, he[i]);
	}
}

void array5(char he[]) {
	printf("���ڿ��� �Է��ϼ��� : ");
	gets(he); // ���ڿ��� �Է¹޴� �Լ� array4�� ������ ����
}

void efun5(void) {
	char he[5]; // �Է°��� ������ �迭
	int i;

	array5(he); // array5�Լ��� he �迭�� �ѱ�
	printf("\n[��°��]\n");
	for (i = 0; i < 5; i++) {
		printf("he[%d] = %c\n", i, he[i]);
	}
}

void array6(char str1[], char str2[]) {
	char tmp;
	int i = 0, size;

	size = sizeof(str1); // char�� 1����Ʈ�� sizeof�� �� ���ڿ� ����
	
	do {
		tmp = str1[i]; // str[i] ��° ���� tmp�� �ӽ�����
		str1[i] = str2[i]; // str2[i] ���� str1[i]�� ������
		str2[i] = tmp; // str2[1]�� str[i]���� ���� tmp�� ���� �����
	} while (++i < size);
}

void efun6(void) {
	char str1[] = "ABCD";
	char str2[] = "1234";

	printf("[��ü �� ��°��] \n");
	printf("str1 = %s, str2 = %s\n", str1, str2);

	array6(str1, str2); // array6�Լ����� �� ���ڿ��� ���� �ٲ� 

	printf("[��ü �� ��°��] \n");
	printf("str1 = %s, str2 = %s\n", str1, str2);
}

void array7pnt(char str[]) { // str�ּҸ� ����
	printf("%s\n", str); // ���� �ּ��� ��ġ���� �迭 ���� ���
}

void efun7(void) {
	char str[] = "ABCDE";
	int i;

	for (i = 0; i < sizeof(str) - 1; i++) { 
		// ���ڿ� �ڿ� null �ֱ� ������ sizeof(str)�� ���� 6�̹Ƿ� -1�� �ؾ���
		array7pnt(&str[i]); // str�� i��° �ε����� �ּҸ� array7pnt�� ���� 
	}
}

void efun8(void) {
	char str[] = "ABCDE";
	int i;

	for (i = sizeof(str) - 2; i >= 0; i--) {
		// ���ڿ� �ڿ� null�� �ֱ� ������ sizeof(str)�� ���� 6�̹Ƿ� -2�� �ؾ���
		array7pnt(&str[i]);
	}
} 

