#include <stdio.h>

int main(int argc, char* argv[]) {
	int i;
	printf("�Է��Ͻ� ���ڿ��� ");

	for (i = 1; i < argc; i++) {
		printf("%s ", argv[i]);
	}

	if (argc <= 1) {
		printf("...�����ϴ�.");
	} else {
		printf("�Դϴ�.");
	}
	return 0;
}