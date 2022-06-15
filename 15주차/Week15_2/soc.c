#include <stdio.h>

void eType(int argc, char* argv[]) {
	char name[10];
	int a1, a2, a3;
	FILE* infoFile, * outFile;
	
	infoFile = fopen(argv[1], "r");
	outFile = fopen(argv[2], "w");

	if (infoFile == NULL) {
		printf("Error opening file : a.txt");
		exit(0);
	}

	while (fscanf(infoFile, "%s%d%d%d", &name, &a1, &a2, &a3) != EOF) {
		fprintf(outFile, "%s %d %d %d\n", name, a1, a2, a3);
	}

	fclose(infoFile);
	fclose(outFile);
}

void score() {
	char name[10];
	int a1, a2, a3;
	FILE* infoFile, * outFile;

	infoFile = fopen("a.txt", "r");
	outFile = fopen("b.txt", "w");
	
	if (infoFile == NULL) {
		printf("Error opening file : a.txt");
		exit(0);
	}

	while (fscanf(infoFile, "%s%d%d%d", &name, &a1, &a2, &a3) != EOF) {
		int sum = a1 + a2 + a3;
		double avg = (double)sum / 3;
		char grade;
		if (avg >= 90 && avg <= 100) {
			grade = 'A';
		} else if (avg >= 80 && avg < 90) {
			grade = 'B';
		} else if (avg >= 70 && avg < 80) {
			grade = 'C';
		} else if (avg >= 60 && avg < 70) {
			grade = 'D';
		} else {
			grade = 'F';
		}
		fprintf(outFile, "%s %d %d %d %d %.1f %c\n", name, a1, a2, a3, a1 + a2 + a3, avg, grade);
	}

	fclose(infoFile);
	fclose(outFile);
}