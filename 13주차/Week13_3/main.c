#include <stdio.h>

int main(int argc, char* argv[]) {
	int i = 0;
	int sum = 0;
	
	if (argc <= 1) {
		printf("�Էµ� �����Ͱ� �����ϴ�.\n");
		return 0;
	}
	for (i = 0; i < argc; i++) {
		sum += atoi(argv[i]);
	}
	printf("���ڿ��� ���ڷ� ��ȯ�� ���� : %d �Դϴ�.\n", sum);

	return 0;
}