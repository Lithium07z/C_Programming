#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

void file01(void) { // 키보드로부터 내용을 입력받아 파일에 출력하라. == 파일에 저장하라
	int ch;
	FILE* fp;

	fp = fopen("sample1.txt", "w"); // sample1.txt를 쓰기모드로 열음

	while ((ch = getchar()) != EOF) { // ctrl + z가 EOF임 EOF가 발생하기 전까지 계속 저장함
		putc(ch, fp);
	}
	fclose(fp);
}

void file02(void) { // 파일의 내용을 화면에 출력하라.
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

void file03(void) { // 파일의 사이즈를 계산하여 출력하라.
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
	printf("파일의 사이즈는 %d바이트입니다.\n", cnt);
}

void file04(void) { // 파일에서 'a' or 'A'의 개수는?
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
	printf("A 혹은 a의 개수는 %d개 입니다.\n", cnt);
}

void file05(void) { // 소문자의 개수와 대문자의 개수를 출력하라.
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
	printf("소문자의 개수는 %d개, 대문자의 개수는 %d개 입니다.\n", cnt1, cnt2);
}

void file06(void) { // 원본파일을 복사하여 복사본 파일을 만드시오
	int ch;
	FILE* fp1, * fp2;

	if ((fp1 = fopen("sample1.txt", "r")) != NULL) {
		fp2 = fopen("sample2.txt", "a"); // append는 파일이 없다면 새로 만들어서 추가하고 있다면 원래 내용 뒤에 추가함

		while ((ch = getc(fp1)) != EOF) {
			putc(ch, fp2);
		}
		fclose(fp1);
		fclose(fp2);
	}
	else printf("file open error.\n");
}

void file07(void) { // "sample3.txt" 파일에 홍길동이라는 이름을 하나 등록해보기
	int ch;
	FILE* fp;
	char name1[] = "당신의 이름은 ";
	char name2[] = " 입니다.";

	if ((fp = fopen("sample3.txt", "r")) != NULL) {
		printf(name1);

		while ((ch = getc(fp)) != EOF) {
			putchar(ch); // UTF-8로 인코딩한 경우 정상적으로 보이지 않을 수 있음
		}
		puts(name2);
		fclose(fp);
	}
	else printf("file open error.\n");
}

void file08(void) {
	int ch;
	FILE* fp1, * fp2;
	char name1[] = "당신의 이름은 ";
	char name2[] = " 입니다.";

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

void file09(void) { // "sample5.txt"파일에 "홍길동/최만두/이길복" 이라는 이름을 등록해보기
	int ch;
	FILE* fp;
	char name1[] = "당신의 이름은 ";
	char name2[] = " 입니다.";

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

void file10(void) { // file09의 결과를 파일에 저장하라. ("sample6.txt")
	int ch;
	FILE* fp1, * fp2;
	char name1[] = "당신의 이름은 ";
	char name2[] = " 입니다.";

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