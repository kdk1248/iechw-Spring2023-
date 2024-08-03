#include <stdio.h>

void swap(int a, int b) //pass by value를 이용한 swap 함수,
{
	int temp = 0; // temp 변수선언과 초기화 
	temp = a; // temp에 a값을 저장
	a = b;  // a에 b값을 저장
	b = temp; //b에 temp값을 저장
}

void pointer_swap(int* a, int* b)// pass by reference를 이용한 swap 함수
{

	int temp = 0; // temp 변수선언과 초기화 
	temp = *a; //temp에 a가 가리키는 값을 저장
	*a = *b; //a가 가리키는 값을 b가 가르키는 값으로 변경
	*b = temp;//b가 가리키는 값을 temp값으로 변경

}

int main() {
	int a = 1, b = 2; // a와b 변수 선언하고 초기화
	printf("변경 이전 값, a = %d, b = %d\n", a, b);

	swap(a, b);// 변수(pass by value)를 이용한 swap 함수 호출
	printf("변경 이후 값, a = %d, b = %d\n", a, b);

	pointer_swap(&a, &b); // 포인터(pass by reference)를 이용한 SWAP 함수 호출
	printf("변경 이후 값, a = %d, b = %d\n", a, b);

	return 0;
}