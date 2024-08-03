#include <stdio.h> 
 
void swap(int* a, int* b) { // pass by value�� �̿��� swap �Լ�
    int temp = *a; // temp�� a�� ����Ű�� ���� ����
    *a = *b;// a�� ����Ű�� ������ b�� ����Ű�� ���� ����
    *b = temp; //b�� ����Ű�� ������ temp�� ����� ���� ����
}
 
void select_sort(int array[], int number) { 
    int i, j, minimum_index; 
    for (i = 0; i < 8; i++) { //�迭�� ũ�⸸ŭ �ݺ� 
        minimum_index = i; // �ּڰ��� ���� �ε���(minimum_index)�� i�� �ʱ�ȭ
        for (j = i + 1; j < 8; j++) { //i ���� �ε������� �迭�� ������ �ݺ�
            if (array[j] < array[minimum_index]) {// �ּڰ��� ���� �ε����� ã�Ƴ�
                minimum_index = j; 
            } 
        } 
        swap(&array[i], &array[minimum_index]); // swap�Լ��� �̿��Ͽ� i�� minimum_index�� �ִ� ���Ҹ� ��ȯ
    } 
} 
 
int main() { 
    int arr[8] = { 4, 7, 3, 8, 2, 10, 25, 1 }; //�迭�� ����
    int number = 8; // �迭�� ũ�⸦ ����
     
    printf("���� �� �迭: "); 
    for (int i = 0; i < 8; i++) { 
        printf("%d ", arr[i]); 
    } 
    printf("\n"); 
     
    select_sort(arr, number); //�Լ��� ȣ���Ͽ� �迭�� ����
     
    printf("���� �� �迭: "); 
    for (int i = 0; i < 8; i++) { 
        printf("%d ", arr[i]); 
    } 
    printf("\n"); 
     
    return 0; 
} 