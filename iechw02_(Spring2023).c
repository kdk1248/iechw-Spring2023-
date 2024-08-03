#include <stdio.h> //stdio.h를 불러옵니다
 
int main() 
{ 
	printf("\n1 x 1 = 1\t2 x 1 = 2\t3 x 1 = 3"); //1단부터 3단까지 출력합니다
	printf("\n1 x 2 = 2\t2 x 2 = 4\t3 x 2 = 6"); 
	printf("\n1 x 3 = 3\t2 x 3 = 6\t3 x 3 = 9"); 
	printf("\n1 x 4 = 4\t2 x 4 = 8\t3 x 4 = 12"); 
	printf("\n1 x 5 = 5\t2 x 5 = 10\t3 x 5 = 15");  
	printf("\n1 x 6 = 6\t2 x 6 = 12\t3 x 6 = 18"); 
	printf("\n1 x 7 = 7\t2 x 7 = 14\t3 x 7 = 21"); 
	printf("\n1 x 8 = 8\t2 x 8 = 16\t3 x 8 = 24"); 
	printf("\n1 x 9 = 9\t2 x 9 = 18\t3 x 9 = 27"); 
	printf("\n"); 
	printf("\n4 x 1 = 4\t5 x 1 = 2\t6 x 1 = 6\t"); //4단부터 3단까지 출력합니다
	printf("\n4 x 2 = 8\t5 x 2 = 2\t6 x 2 = 12\t"); 
	printf("\n4 x 3 = 12\t5 x 3 = 2\t6 x 3 = 18\t"); 
	printf("\n4 x 4 = 16\t5 x 4 = 2\t6 x 4 = 24\t"); 
	printf("\n4 x 5 = 20\t5 x 5 = 2\t6 x 5 = 30\t"); 
	printf("\n4 x 6 = 24\t5 x 6 = 2\t6 x 6 = 36\t"); 
	printf("\n4 x 7 = 28\t5 x 7 = 2\t6 x 7 = 42\t"); 
	printf("\n4 x 8 = 32\t5 x 8 = 2\t6 x 8 = 48\t"); 
	printf("\n4 x 9 = 36\t5 x 9 = 2\t6 x 9 = 54\t"); 
	printf("\n");  
	printf("\n7 x 1 = 7\t8 x 1 = 8\t9 x 1 = 9\t"); //7단부터 9단까지 출력합니다
	printf("\n7 x 2 = 14\t8 x 2 = 16\t9 x 2 = 18\t"); 
	printf("\n7 x 3 = 21\t8 x 3 = 24\t9 x 3 = 27\t"); 
	printf("\n7 x 4 = 28\t8 x 4 = 32\t9 x 4 = 36\t"); 
	printf("\n7 x 5 = 35\t8 x 5 = 42\t9 x 5 = 45\t"); 
	printf("\n7 x 6 = 42\t8 x 6 = 48\t9 x 6 = 54\t"); 
	printf("\n7 x 7 = 79\t8 x 7 = 56\t9 x 7 = 63\t"); 
	printf("\n7 x 8 = 56\t8 x 8 = 64\t9 x 8 = 72\t"); 
	printf("\n7 x 9 = 63\t8 x 9 = 72\t9 x 9 = 81\t"); 
	 
	 
	int num; // int형 변수 num 를 선언합니다
	 
	printf("\n\n출력할 단의 정수 한 개를 입력하세요:"); // 문자열 정수값을 출력합니다
	scanf("%d",&num); // num에 %d 형태(정수형태) 값을 대입하고, 대입한 값을 이용하여 변수를 출력합니다
	 
	printf("\n%d x 1 = %d\n", num, num * 1); //%d 위치에 변수가 대입되고, 계산되어 출력합니다
	printf("%d x 2 = %d\n", num, num * 2);  
	printf("%d x 3 = %d\n", num, num * 3);  
	printf("%d x 4 = %d\n", num, num * 4);  
	printf("%d x 5 = %d\n", num, num * 5);   
	printf("%d x 6 = %d\n", num, num * 6);  
	printf("%d x 7 = %d\n", num, num * 7);   
	printf("%d x 8 = %d\n", num, num * 8);  
	printf("%d x 9 = %d\n", num, num * 9);  
	 
		return ; 
} 
 