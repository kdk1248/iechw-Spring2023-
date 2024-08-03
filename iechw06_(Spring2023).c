#include <stdio.h>

void swap(int a, int b) //pass by value�� �̿��� swap �Լ�,
{
	int temp = 0; // temp ��������� �ʱ�ȭ 
	temp = a; // temp�� a���� ����
	a = b;  // a�� b���� ����
	b = temp; //b�� temp���� ����
}

void pointer_swap(int* a, int* b)// pass by reference�� �̿��� swap �Լ�
{

	int temp = 0; // temp ��������� �ʱ�ȭ 
	temp = *a; //temp�� a�� ����Ű�� ���� ����
	*a = *b; //a�� ����Ű�� ���� b�� ����Ű�� ������ ����
	*b = temp;//b�� ����Ű�� ���� temp������ ����

}

int main() {
	int a = 1, b = 2; // a��b ���� �����ϰ� �ʱ�ȭ
	printf("���� ���� ��, a = %d, b = %d\n", a, b);

	swap(a, b);// ����(pass by value)�� �̿��� swap �Լ� ȣ��
	printf("���� ���� ��, a = %d, b = %d\n", a, b);

	pointer_swap(&a, &b); // ������(pass by reference)�� �̿��� SWAP �Լ� ȣ��
	printf("���� ���� ��, a = %d, b = %d\n", a, b);

	return 0;
}