#include <stdio.h>

void swap(int* a, int* b) { // pass by value를 이용한 swap 함수
    int temp = *a; // temp에 a가 가리키는 값을 저장
    *a = *b; // a가 가리키는 변수에 b가 가리키는 값을 저장
    *b = temp; //b가 가리키는 변수에 temp에 저장된 값을 저장
}

void bubble_sort(int array[], int number) {
    int i, j;
    for (i = 0; i < 8; i++) { // 배열의 길이 만큼 반복
        for (j = 0; j < 8 - i - 1; j++) { //숫자들 끼리 인접한 요소를 비교하기 위해서 배열의 길이에서 i를 뺀 만큼 반복
            if (array[j] > array[j + 1]) { // 해당 요소가 다음 요소보다 크다면 요소를 바꿈
                swap(&array[j], &array[j + 1]);
            }
        }
    }
}

int main() { // main, 프로그램 시작점
    int arr[8] = { 4, 7, 3, 8, 2, 10, 25, 1 }; // 초기화 된 크기가 8인 정수형 배열 생성
    int number = 8; // 배열의 길이 저장
    bubble_sort(arr,number); // 배열 호출하여 정렬
    printf("정렬된 배열: ");
    for (int i = 0; i < 8; i++) { //배열의 요소를 출력
        printf("%d ", arr[i]);
    }
    return 0;
}
