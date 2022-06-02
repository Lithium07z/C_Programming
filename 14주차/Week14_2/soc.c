#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

void file01(void) { // Ű����κ��� ������ �Է¹޾� ���Ͽ� ����϶�. == ���Ͽ� �����϶�
	int ch;
	FILE* fp;

	fp = fopen("sample1.txt", "w"); // sample1.txt�� ������� ����

	while ((ch = getchar()) != EOF) { // ctrl + z�� EOF�� EOF�� �߻��ϱ� ������ ��� ������
		putc(ch, fp);
	}
	fclose(fp);
}

void file02(void) { // ������ ������ ȭ�鿡 ����϶�.
	int ch;
	FILE* fp;

	if ((fp = fopen("sample1.txt", "r")) != NULL) {
		while ((ch = getc(fp)) != EOF) {
			putchar(ch);
		}
		fclose(fp);
	}
	else printf("file open error.\n");
}

void file03(void) { // ������ ����� ����Ͽ� ����϶�.
	int ch;
	int cnt = 0;
	FILE* fp;

	if ((fp = fopen("sample1.txt", "r")) != NULL) {
		while ((ch = getc(fp)) != EOF) {
			cnt++;
		}
		fclose(fp);
	}
	else printf("file open error.\n");
	printf("������ ������� %d����Ʈ�Դϴ�.\n", cnt);
}

void file04(void) { // ���Ͽ��� 'a' or 'A'�� ������?
	int ch;
	int cnt = 0;
	FILE* fp;

	if ((fp = fopen("sample1.txt", "r")) != NULL) {
		while ((ch = getc(fp)) != EOF) {
			if (ch == 'a' || ch == 'A') {
				cnt++;
			}
		}
		fclose(fp);
	}
	else printf("file open error.\n");
	printf("A Ȥ�� a�� ������ %d�� �Դϴ�.\n", cnt);
}

void file05(void) { // �ҹ����� ������ �빮���� ������ ����϶�.
	int ch;
	int cnt1 = 0, cnt2 = 0;
	FILE* fp;

	if ((fp = fopen("sample1.txt", "r")) != NULL) {
		while ((ch = getc(fp)) != EOF) {
			if (ch >= 'a' && ch <= 'z') {
				cnt1++;
			}
			else if (ch >= 'A' && ch <= 'Z') {
				cnt2++;
			}
		}
		fclose(fp);
	}
	else printf("file open error.\n");
	printf("�ҹ����� ������ %d��, �빮���� ������ %d�� �Դϴ�.\n", cnt1, cnt2);
}

void file06(void) { // ���������� �����Ͽ� ���纻 ������ ����ÿ�
	int ch;
	FILE* fp1, * fp2;

	if ((fp1 = fopen("sample1.txt", "r")) != NULL) {
		fp2 = fopen("sample2.txt", "a"); // append�� ������ ���ٸ� ���� ���� �߰��ϰ� �ִٸ� ���� ���� �ڿ� �߰���

		while ((ch = getc(fp1)) != EOF) {
			putc(ch, fp2);
		}
		fclose(fp1);
		fclose(fp2);
	}
	else printf("file open error.\n");
}

void file07(void) { // "sample3.txt" ���Ͽ� ȫ�浿�̶�� �̸��� �ϳ� ����غ���
	int ch;
	FILE* fp;
	char name1[] = "����� �̸��� ";
	char name2[] = " �Դϴ�.";

	if ((fp = fopen("sample3.txt", "r")) != NULL) {
		printf(name1);

		while ((ch = getc(fp)) != EOF) {
			putchar(ch); // UTF-8�� ���ڵ��� ��� ���������� ������ ���� �� ����
		}
		puts(name2);
		fclose(fp);
	}
	else printf("file open error.\n");
}

void file08(void) {
	int ch;
	FILE* fp1, * fp2;
	char name1[] = "����� �̸��� ";
	char name2[] = " �Դϴ�.";

	if ((fp1 = fopen("sample3.txt", "r")) != NULL) {
		fp2 = fopen("sample4.txt", "w");

		fputs(name1, fp2);

		while ((ch = getc(fp1)) != EOF) {
			putc(ch, fp2);
		}
		fputs(name2, fp2);
	}
	else printf("file open error.\n");
}

void file09(void) { // "sample5.txt"���Ͽ� "ȫ�浿/�ָ���/�̱溹" �̶�� �̸��� ����غ���
	int ch;
	FILE* fp;
	char name1[] = "����� �̸��� ";
	char name2[] = " �Դϴ�.";

	if ((fp = fopen("sample5.txt", "r")) != NULL) {
		printf(name1);

		while ((ch = getc(fp)) != EOF) {
			if (ch == '/') {
				puts(name2);
				printf(name1);
				continue;
			}
			else {
				putchar(ch);
			}
		}

		puts(name2);
		fclose(fp);
	}
	else printf("file open error.\n");
}

void file10(void) { // file09�� ����� ���Ͽ� �����϶�. ("sample6.txt")
	int ch;
	FILE* fp1, * fp2;
	char name1[] = "����� �̸��� ";
	char name2[] = " �Դϴ�.";

	if ((fp1 = fopen("sample5.txt", "r")) != NULL) {
		fp2 = fopen("sample6.txt", "w");
		fputs(name1, fp2);

		while ((ch = getc(fp1)) != EOF) {
			if (ch == '/') {
				fputs(name2, fp2);
				fputs("\n", fp2);
				fputs(name1, fp2);
				continue;
			}
			else {
				putc(ch, fp2);
			}
		}

		fputs(name2, fp2);
	}
}