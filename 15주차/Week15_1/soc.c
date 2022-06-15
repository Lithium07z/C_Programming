#include <stdio.h>

void file01(void) {
	char name[10];
	char FileName[10] = "data.txt"; // �̹� �����ϴ� ���� data.txt�� FileName�� ����
	int a1, a2, a3;
	FILE* infoFile;

	infoFile = fopen(FileName, "r"); // data.txt������ �б���� ��� infoFile�� ����

	if (infoFile == NULL) { // data.txt�� ���ٸ�
		printf("Error opening file : %s", FileName); // ���� ���� ����  
		exit(0);
	}

	while (fscanf(infoFile, "%s%d%d%d", name, &a1, &a2, &a3) != EOF) { // ���� ������ �ݺ��ؼ� %s%d%d%d �������� ����
		printf("\t%s\tis\t%d\t%d\t%d\tsum=%d\n", name, a1, a2, a3, a1 + a2 + a3);
	}
	fclose(infoFile);
}

void file02(void) {
	char name[10];
	char FileName[10] = "data.txt"; // �̹� �����ϴ� ���� data.txt�� FileName�� ����
	int a1, a2, a3;
	FILE* infoFile, * outFile; // ���� ���ϰ� ����� ������ ���� ������

	infoFile = fopen(FileName, "r"); // data.txt������ �б���� ��� infoFile�� ����
	outFile = fopen("outfile.txt", "w"); // outfile.txt������ ���ٸ� ����� ������� ��� outfile�� ����

	if (infoFile == NULL) { // data.txt�� ���ٸ�
		printf("Error opening file: %s", FileName); // ���� ���� ����  
		exit(0);
	}

	while (fscanf(infoFile, "%s%d%d%d", name, &a1, &a2, &a3) != EOF) { // ���� ������ �ݺ��ؼ� %s%d%d%d �������� ����
		fprintf(outFile, "\t%s\tis\t%d\t%d\t%d\tsum=%d\n", name, a1, a2, a3, a1 + a2 + a3);
	}
	fclose(infoFile); // ���� �ݱ�
	fclose(outFile); // ���� �ݱ� 
}

void file03(void) {
	char name[10]; // �̸� 
	char FileName[10] = "data.txt"; // �̹� �����ϴ� ���� data.txt�� FileName�� ����
	int a1, a2, a3; // ����
	FILE* infoFile, * outFile; // ���� ���ϰ� ����� ������ ���� ������

	infoFile = fopen(FileName, "r"); // data.txt������ �б���� ��� infoFile�� ����
	outFile = fopen("outfile.txt", "w"); // outfile.txt������ ���ٸ� ����� ������� ��� outfile�� ����

	if (infoFile == NULL) { // data.txt�� ���ٸ�
		printf("Error opening file: %s", FileName); // ���� ���� ����  
		exit(0);
	}

	while (fscanf(infoFile, "%s%d%d%d", name, &a1, &a2, &a3) != EOF) { // ���� ������ �ݺ��ؼ� %s%d%d%d �������� ����
		fputs("\t---------------------------------------------------------------------\n", outFile); // fputs�� ���� �̸��� �ڷΰ�
		fprintf(outFile, "\t%s\tis\t%d\t%d\t%d\tsum=%d\n", name, a1, a2, a3, a1 + a2 + a3); // ���Ͽ� ���
	}
	fputs("\t---------------------------------------------------------------------\n", outFile);
	fclose(infoFile); // ���� �ݱ�
	fclose(outFile); // ���� �ݱ�
}

int file04(int argc, char* argv[]) {
	int ch;
	FILE* fp1;

	if (argc != 2) { // ���ڰ� 2���� �ƴ϶�� ���� ������ ������ �ִ� ���̹Ƿ�
		printf("invalid argument.\n"); // ���� ���� ��� 
		exit(1);
	}

	if ((fp1 = fopen(argv[1], "r")) == NULL) { // argv1�� ������ ����ִٸ�
		printf("%s not found.\n", argv[1]); // not found ���� ���
		exit(1);
	}

	while ((ch = getc(fp1)) != EOF) { // ������ ���� �� ���� �ݺ�
		putchar(ch); 
	}
	fclose(fp1);
	return 0;
}

int file05(int argc, char* argv[]) {
	int ch, cnt = 0;
	FILE* fp1;

	if (argc != 2) { // ���ڰ� 2���� �ƴ϶�� ���� ������ ������ �ִ� ���̹Ƿ�
		printf("invalid argument.\n"); // ���� ���� ��� 
		exit(1);
	}

	if ((fp1 = fopen(argv[1], "r")) == NULL) { // argv1�� ������ ����ִٸ�
		printf("%s not found.\n", argv[1]); // not found ���� ���
		exit(1);
	}
	
	while ((ch = getc(fp1)) != EOF) { // ������ ������ �ݺ�
		if ((ch == 's') || (ch == 'S')) { // ���� ���ڰ� s �Ǵ� S�� ��� 
			cnt++; // ���� ���� 
		}
	}
	printf("s �Ǵ� S������ ������ %d�Դϴ�. \n", cnt); // ���� ��� 
	fclose(fp1); // ���� �ݱ� 
	return 0;
}

int file06(int argc, char* argv[]) {
	int ch, cnt = 0;
	FILE* fp1;

	if (argc != 3) { // ���ڰ� 3���� �ƴϸ� ���� ������ ������ �ִ� ���̹Ƿ�
		printf("invalid argument.\n"); // ���� ���� ���
		exit(1);
	}

	if ((fp1 = fopen(argv[1], "r")) == NULL) { // argv1�� ������ ����ִٸ�
		printf("%s not found.\n", argv[1]); // not found ���� ���
		exit(1);
	}

	if (*argv[2] == '0') { // ���� ������ �޴��� 0�̶��
		while ((ch = getc(fp1)) != EOF) { // �״�� ���
			putchar(ch);
		}
	} else if (*argv[2] == '1') { // ���� ������ �޴��� 1�̶��
		while ((ch = getc(fp1)) != EOF) {
			putchar((ch >= 'a' && ch <= 'z') ? ch - 32 :ch);
		}   // ���� �ϳ��� �˻��Ͽ� �ҹ����� ��� �빮�ڷ� �ٲ���
	} else if (*argv[2] == '2') { // ���� ������ �޴��� 2���
		while ((ch = getc(fp1)) != EOF) {
			putchar((ch >= 'A' && ch <= 'Z') ? ch + 32 :ch);
		}   // ���� �ϳ��� �˻��Ͽ� �빮���� ��� �ҹ��ڷ� �ٲ���
	} else { // �� �̿��� �޴� ��ȣ�� ��� �߸� �Է��� ������ ����
		printf("���� �μ��� �߸� �Է��ϼ̽��ϴ�. �μ��� [0~2]������ �����մϴ�.\n");
	}
	fclose(fp1); // ���� �ݱ� 
	return 0;
}