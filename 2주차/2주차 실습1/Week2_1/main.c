#include <stdio.h>

int main(void)
{
	int j = 1;
	int sum = 0;
	for (int i = 1; i <= 5; i++) {
		sum += i;
		for (; j <= sum; j++) {
			printf("%d", j);
			printf(" ");
		}
		printf("\n");
	}
}