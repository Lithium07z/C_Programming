#include <stdio.h>

int main(int argc, char* argv[]) {
	int i;
	printf("입력하신 문자열은 ");

	for (i = 1; i < argc; i++) {
		printf("%s ", argv[i]);
	}

	if (argc <= 1) {
		printf("...없습니다.");
	} else {
		printf("입니다.");
	}
	return 0;
}