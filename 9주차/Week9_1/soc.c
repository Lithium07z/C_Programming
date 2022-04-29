#include <stdio.h>

void p1(void) {
	int x;

	x = 25;

	printf("x = %d\n&x = %u\n", x, &x); // x의 값 5와 변수 x의 주소값 출력 주소값은 매 출력마다 달라짐
}

void p2(void) {
	int *ptr, a = 10, b = 20;

	ptr = &a; // 포인터변수 ptr에 변수 a의 주소 값을 저장함 
	printf("%d\n", *ptr); // 포인터 변수 ptr이 가르키는 값을 출력함 ptr은 a의 값이 있는 곳을 가리키므로 a가 출력됨

	ptr = &b; // 포인터변수 ptr에 변수 b의 주소 값을 저장함 
	printf("%d\n", *ptr); // 포인터 변수 ptr이 가르키는 값을 출력함 ptr은 b의 값이 있는 곳을 가리키므로 b가 출력됨

	*ptr = 30; // 포인터변수 ptr이 가리키는 곳에 30을 넣음 현재 ptr변수가 가리키는 곳은 마지막에 b였으므로
	printf("%d\n", b); // b에 30이 들어가게 되어 출력하면 b의 값은 30이 됨 
}

void p3(void) {
	int a, *p, **q;

	a = 12; // 변수 a에 12를 넣음
	p = &a; // 포인터변수 p에 a의 주소값을 넣음
	q = &p; // 포인터변수 q에 p의 주소를 넣음 q > p > a(12)의 형태 
	// p == &a, *p == a, &p == q, *q == &p, **q == a
	printf("a = %d &a = %d\n", a, &a); // a의 값과 a의 주소값을 출력
	printf("p = %d &p = %d *p = %d\n", p, &p, *p); // p의 값과 p의 주소값, p가 가리키는 주소의 값을 출력
	printf("q = %d &q = %d *q = %d **q = %d\n", q, &q, *q, **q); // q의 값과 q의 주소값, q가 가리키는 주소의 값을 출력
	// 마지막으로 q가 가리키는 주소가 가리키는 곳의 값을 출력 *q == &p이고 **q = 12임 
}

void p4(void) {
	int i, j, *pt;

	i = 12; // 변수 i에 12를 넣음 
	pt = &i; // 포인터변수 pt에 변수 i의 주소를 넣음 
	j = *pt; // 변수 j에 포인터변수 pt가 가리키는 곳의 값을 넣음 == (j = i) 

	printf("i = %d\nj = %d\n", i, j);
}

void sub(int* pt_x, int* pt_y, int* pt_z) { // 받은 주소들이 가리키는 곳의 값을 가짐
	*pt_z = *pt_x - *pt_y; // 주소에 해당하는 값들로 연산함 
}

void p5(void) {
	int x = 15, y = 10, z;

	sub(&x, &y, &z); // sub함수에 서로 뺄 변수와 결과값을 저장할 변수의 주소를 보냄 

	printf("%d - %d = %d\n", x, y, z);
}

void change(int *pt_x, int *pt_y) { // 받은 주소가 가리키는 값을 가져옴 
	int temp = *pt_x; // 서로 바꿔줌 
	*pt_x = *pt_y;
	*pt_y = temp;
}

void p6(void) {
	int x = 5, y = 10;

	printf("x = %3d y = %3d\n", x, y);

	change(&x, &y); // 서로 값을 바꿔치기할 두 변수의 주소 값을 change함수에 보냄 

	printf("x = %3d y = %3d\n", x, y);
}

void p7(void) {
	char *_ptr; // 포인터변수 _ptr선언
	int i;

	_ptr = "abcde"; // _ptr에 문자열 리터럴 "abcde"의 주소 저장 

	printf("%d [%d]\n", _ptr, _ptr + 1); // 문자열 시작 주소, 시작 다음 주소 출력 
	printf("%d [%s]\n", _ptr, _ptr); // %d로 문자열 시작 주소 출력, %s로 문자열 전체출력 

	for (i = 0; i < 5; i++) {
		printf("%d [%c]\n", _ptr + i, *(_ptr + i)); 
	} // %d로 문자열 각각의 문자들 주소 출력, 문자열 주소들이 가리키는 값 출력
}

void eCopy(char str[], char etr[]) { // 두 문자열 배열을 받음 
	strcpy(str, etr); // strcpy함수를 이용해 문자열 복사 후 넣음 
}

void p8(void) {
	char str[50];
	char etr[50] = "This is a sample";

	eCopy(str, etr); // 복사해야 할 문자열 배열과 복사받을 문자열 배열을 eCopy함수로 보냄 

	printf("%s\n", str);
}

void p9(void) {
	static char *name[] = { "kim", "park", "jeong" }; // 선언과 동시에 초기화 하므로 크기 없어도 됨 
	// 위의 배열은 포인터 배열임 즉, 배열 내 변수들이 모두 char형 데이터를 가리키는 주소임 

	int i, j;
	char** ptr; // 이중 포인터 변수 ptr 선언

	ptr = name; // ptr은 이중 포인터이므로 먼저 name을 가리키고   

	for (i = 0; i < 3; i++) {
		printf("*name[%3d] = %c\n", i, **(ptr + i)); // name[i]가 가리키는 주소에서 또 가리킴 
	}   // name[0] > kim의 주소 *name[0] > kim의 주소에서 k의 주소 
	for (i = 0; i < 3; i++) {
		printf("%s\n", name[i]); // name 배열의 i 번째 주소가 가리키는 값을 출력, kim ~ jeong
	}
	for (i = 0; i < 3; i++) {
		for (j = 0; *(*(ptr + i) + j) != '\0'; j++) {
			printf("%c", *(*(ptr + i) + j));
		}
		putchar('\n');
	}
	//printf("%d %d", ptr, name);
	/*  *(*(ptr + i) + j) 설명
	*   >> (ptr + i) : name 배열의 주소 값들을 차례로 가져옴 Ex) ptr + 0 > "kim"의 주소, ptr + 1 > "park"의 주소
	*      *(ptr + i) : 위에서 가져온 주소 값의 첫 번째 주소을 가리킴 이후 + j로 그 뒤 주소들도 차례로 가져옴
	*      Ex) *(ptr + 0) > k, *(ptr + 1) > p, *(ptr + i) > j 
	*      *(*(ptr + i) + j) : null이 아닐때 까지 다음 주소로 이동함
	*	   Ex) *(*(ptr + 0) + 0) > k, *(*(ptr + 0) + 1) > i, *(*(ptr + 0) + 2) > m
	*	
	*	(ptr + 0) > kim의 메모리 주소
	*   *(ptr + 0) > kim의 첫 번째 메모리 주소, k
	*   *(ptr + 0) + 1 > kim의 두 번째 메모리 주소, i 
	*   *(*(ptr + 0) + 1) > 값 i 
	*   문자열 kim을 가리키는 주소가 있고 kim에서 k, i, m을 가리키는 주소가 따로 있다고 생각해야함 
	*   따라서 k에 접근하고 싶다면 kim의 주소에 접근 > k의 주소에 접근, k 값을 가져옴 
	*/
}

void p10(void) {
	int* ptr[2][2]; //
	int i = 1, j = 2, k = 3, l = 4;
	int r, c;

	ptr[0][0] = &i; // 배열 0, 0에 변수 i의 주소값 저장 
	ptr[0][1] = &j; // 배열 0, 1에 변수 j의 주소값 저장 
	ptr[1][0] = &k; // 배열 1, 0에 변수 k의 주소값 저장 
	ptr[1][1] = &l; // 배열 1, 1에 변수 l의 주소값 저장 

	for (r = 0; r < 2; r++) {
		for (c = 0; c < 2; c++) {
			printf("%3d %3d %3d \n", *ptr[r][c], **ptr[r] + c, **(*ptr));
		} 
	}
	/*  *ptr[r][c] > ptr[r][c]는 값의 주소 이므로 *ptr[r][c]를 이용해 값의 주소가 가리키는 값을 가져옴
	*   **ptr[r] + c > *ptr[r]은 배열의 행 주소를 가져옴 ptr[0], ptr[1]
	*                > **ptr[r]은 배열의 행 주소가 가리키는 첫 번째 값을 가져옴 ptr[0][0], ptr[1][0]
	*                > **ptr[r] + c는 첫 값 다음 값들을 가져옴  
	*                Ex) **ptr[0] + 0 > 1, **ptr[0] + 1 > 2
	*   **(*ptr) > *ptr은 *ptr배열의 시작인 ptr[0][0]를 가리킴
	*            > *(*ptr)은 ptr[0][0]이 가리키는 주소를 가리킴 (&i)
	*            > **(*ptr)은 ptr[0][0]이 가리키는 주소가 가리키는 주소의 값을 가져옴 (i)
	*/
}