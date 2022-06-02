#include <stdio.h>
#define STR(str) printf("%s = %d\n", str, eLen(str));

int eLen(char* str) {
	int len = 0;
	while (*str++) {
		len++;
	}
	return len;
}

void fun1(void) {
	char a[] = "Hello";
	STR(a);
	STR("Sample");
}

#define PRN(str) printf("매크로 출력 : %s\n", str);;

void eConcate(char *str1, char *str2, char *resu) {
	while (*str1) {
		*resu++ = *str1++;
	}
	while (*str2) {
		*resu++ = *str2++;
	}
	*resu = 0;
}

void fun2(void) {
	char resu[30];
	char str1[] = "Hello";
	char str2[] = "Sample";

	eConcate(str1, str2, resu);

	printf("합쳐진 문자열 : %s\n", resu);
	PRN(resu);
}
