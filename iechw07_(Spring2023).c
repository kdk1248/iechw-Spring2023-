#include <stdio.h>

void swap(int* a, int* b) { // pass by value�� �̿��� swap �Լ�
    int temp = *a; // temp�� a�� ����Ű�� ���� ����
    *a = *b; // a�� ����Ű�� ������ b�� ����Ű�� ���� ����
    *b = temp; //b�� ����Ű�� ������ temp�� ����� ���� ����
}

void bubble_sort(int array[], int number) {
    int i, j;
    for (i = 0; i < 8; i++) { // �迭�� ���� ��ŭ �ݺ�
        for (j = 0; j < 8 - i - 1; j++) { //���ڵ� ���� ������ ��Ҹ� ���ϱ� ���ؼ� �迭�� ���̿��� i�� �� ��ŭ �ݺ�
            if (array[j] > array[j + 1]) { // �ش� ��Ұ� ���� ��Һ��� ũ�ٸ� ��Ҹ� �ٲ�
                swap(&array[j], &array[j + 1]);
            }
        }
    }
}

int main() { // main, ���α׷� ������
    int arr[8] = { 4, 7, 3, 8, 2, 10, 25, 1 }; // �ʱ�ȭ �� ũ�Ⱑ 8�� ������ �迭 ����
    int number = 8; // �迭�� ���� ����
    bubble_sort(arr,number); // �迭 ȣ���Ͽ� ����
    printf("���ĵ� �迭: ");
    for (int i = 0; i < 8; i++) { //�迭�� ��Ҹ� ���
        printf("%d ", arr[i]);
    }
    return 0;
}
