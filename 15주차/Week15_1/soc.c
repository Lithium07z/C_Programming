#include <stdio.h>

void file01(void) {
	char name[10];
	char FileName[10] = "data.txt"; // 이미 존재하는 파일 data.txt를 FileName에 저장
	int a1, a2, a3;
	FILE* infoFile;

	infoFile = fopen(FileName, "r"); // data.txt파일을 읽기모드로 열어서 infoFile에 저장

	if (infoFile == NULL) { // data.txt가 없다면
		printf("Error opening file : %s", FileName); // 파일 오픈 오류  
		exit(0);
	}

	while (fscanf(infoFile, "%s%d%d%d", name, &a1, &a2, &a3) != EOF) { // 파일 끝까지 반복해서 %s%d%d%d 형식으로 읽음
		printf("\t%s\tis\t%d\t%d\t%d\tsum=%d\n", name, a1, a2, a3, a1 + a2 + a3);
	}
	fclose(infoFile);
}

void file02(void) {
	char name[10];
	char FileName[10] = "data.txt"; // 이미 존재하는 파일 data.txt를 FileName에 저장
	int a1, a2, a3;
	FILE* infoFile, * outFile; // 원본 파일과 출력할 파일의 파일 포인터

	infoFile = fopen(FileName, "r"); // data.txt파일을 읽기모드로 열어서 infoFile에 저장
	outFile = fopen("outfile.txt", "w"); // outfile.txt파일이 없다면 만들고 쓰기모드로 열어서 outfile에 저장

	if (infoFile == NULL) { // data.txt가 없다면
		printf("Error opening file: %s", FileName); // 파일 오픈 오류  
		exit(0);
	}

	while (fscanf(infoFile, "%s%d%d%d", name, &a1, &a2, &a3) != EOF) { // 파일 끝까지 반복해서 %s%d%d%d 형식으로 읽음
		fprintf(outFile, "\t%s\tis\t%d\t%d\t%d\tsum=%d\n", name, a1, a2, a3, a1 + a2 + a3);
	}
	fclose(infoFile); // 파일 닫기
	fclose(outFile); // 파일 닫기 
}

void file03(void) {
	char name[10]; // 이름 
	char FileName[10] = "data.txt"; // 이미 존재하는 파일 data.txt를 FileName에 저장
	int a1, a2, a3; // 점수
	FILE* infoFile, * outFile; // 원본 파일과 출력할 파일의 파일 포인터

	infoFile = fopen(FileName, "r"); // data.txt파일을 읽기모드로 열어서 infoFile에 저장
	outFile = fopen("outfile.txt", "w"); // outfile.txt파일이 없다면 만들고 쓰기모드로 열어서 outfile에 저장

	if (infoFile == NULL) { // data.txt가 없다면
		printf("Error opening file: %s", FileName); // 파일 오픈 오류  
		exit(0);
	}

	while (fscanf(infoFile, "%s%d%d%d", name, &a1, &a2, &a3) != EOF) { // 파일 끝까지 반복해서 %s%d%d%d 형식으로 읽음
		fputs("\t---------------------------------------------------------------------\n", outFile); // fputs는 파일 이름이 뒤로감
		fprintf(outFile, "\t%s\tis\t%d\t%d\t%d\tsum=%d\n", name, a1, a2, a3, a1 + a2 + a3); // 파일에 출력
	}
	fputs("\t---------------------------------------------------------------------\n", outFile);
	fclose(infoFile); // 파일 닫기
	fclose(outFile); // 파일 닫기
}

int file04(int argc, char* argv[]) {
	int ch;
	FILE* fp1;

	if (argc != 2) { // 인자가 2개가 아니라면 인자 개수에 문제가 있는 것이므로
		printf("invalid argument.\n"); // 인자 오류 출력 
		exit(1);
	}

	if ((fp1 = fopen(argv[1], "r")) == NULL) { // argv1의 파일이 비어있다면
		printf("%s not found.\n", argv[1]); // not found 오류 출력
		exit(1);
	}

	while ((ch = getc(fp1)) != EOF) { // 파일이 끝날 때 까지 반복
		putchar(ch); 
	}
	fclose(fp1);
	return 0;
}

int file05(int argc, char* argv[]) {
	int ch, cnt = 0;
	FILE* fp1;

	if (argc != 2) { // 인자가 2개가 아니라면 인자 개수에 문제가 있는 것이므로
		printf("invalid argument.\n"); // 인자 오류 출력 
		exit(1);
	}

	if ((fp1 = fopen(argv[1], "r")) == NULL) { // argv1의 파일이 비어있다면
		printf("%s not found.\n", argv[1]); // not found 오류 출력
		exit(1);
	}
	
	while ((ch = getc(fp1)) != EOF) { // 파일의 끝까지 반복
		if ((ch == 's') || (ch == 'S')) { // 만약 글자가 s 또는 S인 경우 
			cnt++; // 개수 증가 
		}
	}
	printf("s 또는 S문자의 개수는 %d입니다. \n", cnt); // 개수 출력 
	fclose(fp1); // 파일 닫기 
	return 0;
}

int file06(int argc, char* argv[]) {
	int ch, cnt = 0;
	FILE* fp1;

	if (argc != 3) { // 인자가 3개가 아니면 인자 갯수에 문제가 있는 것이므로
		printf("invalid argument.\n"); // 인자 오류 출력
		exit(1);
	}

	if ((fp1 = fopen(argv[1], "r")) == NULL) { // argv1의 파일이 비어있다면
		printf("%s not found.\n", argv[1]); // not found 오류 출력
		exit(1);
	}

	if (*argv[2] == '0') { // 만약 선택한 메뉴가 0이라면
		while ((ch = getc(fp1)) != EOF) { // 그대로 출력
			putchar(ch);
		}
	} else if (*argv[2] == '1') { // 만약 선택한 메뉴가 1이라면
		while ((ch = getc(fp1)) != EOF) {
			putchar((ch >= 'a' && ch <= 'z') ? ch - 32 :ch);
		}   // 글자 하나씩 검사하여 소문자인 경우 대문자로 바꿔줌
	} else if (*argv[2] == '2') { // 만약 선택한 메뉴가 2라면
		while ((ch = getc(fp1)) != EOF) {
			putchar((ch >= 'A' && ch <= 'Z') ? ch + 32 :ch);
		}   // 글자 하나씩 검사하여 대문자인 경우 소문자로 바꿔줌
	} else { // 그 이외의 메뉴 번호는 모두 잘못 입력한 것으로 간주
		printf("선택 인수를 잘못 입력하셨습니다. 인수는 [0~2]까지만 가능합니다.\n");
	}
	fclose(fp1); // 파일 닫기 
	return 0;
}