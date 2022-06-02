#include <stdio.h>

int main(int argc, char* argv[]) {
	int i = 0;
	int sum = 0;
	
	if (argc <= 1) {
		printf("입력된 데이터가 없습니다.\n");
		return 0;
	}
	for (i = 0; i < argc; i++) {
		sum += atoi(argv[i]);
	}
	printf("문자열을 숫자로 변환한 합은 : %d 입니다.\n", sum);

	return 0;
}