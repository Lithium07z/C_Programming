#include <stdio.h>

int main(void)
{
	int value[] = { 5000, 15000, 2000, 7000, 10000 };
	for (int i = 0; i < sizeof(value) / sizeof(value[0]); i++) {
		printf("[%d]", i + 1);
		for (int j = 0; j < (value[i] / 1000); j++) {
			printf("бс ");
		}
		printf("(%d)\n", value[i]);
	}
}