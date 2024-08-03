#include <stdio.h> 
 
void swap(int* a, int* b) { // pass by value를 이용한 swap 함수
    int temp = *a; // temp에 a가 가리키는 값을 저장
    *a = *b;// a가 가리키는 변수에 b가 가리키는 값을 저장
    *b = temp; //b가 가리키는 변수에 temp에 저장된 값을 저장
}
 
void select_sort(int array[], int number) { 
    int i, j, minimum_index; 
    for (i = 0; i < 8; i++) { //배열의 크기만큼 반복 
        minimum_index = i; // 최솟값을 가진 인덱스(minimum_index)를 i로 초기화
        for (j = i + 1; j < 8; j++) { //i 다음 인덱스부터 배열의 끝까지 반복
            if (array[j] < array[minimum_index]) {// 최솟값을 가진 인덱스를 찾아냄
                minimum_index = j; 
            } 
        } 
        swap(&array[i], &array[minimum_index]); // swap함수를 이용하여 i와 minimum_index에 있는 원소를 교환
    } 
} 
 
int main() { 
    int arr[8] = { 4, 7, 3, 8, 2, 10, 25, 1 }; //배열을 정의
    int number = 8; // 배열의 크기를 정의
     
    printf("정렬 전 배열: "); 
    for (int i = 0; i < 8; i++) { 
        printf("%d ", arr[i]); 
    } 
    printf("\n"); 
     
    select_sort(arr, number); //함수를 호출하여 배열을 정렬
     
    printf("정렬 후 배열: "); 
    for (int i = 0; i < 8; i++) { 
        printf("%d ", arr[i]); 
    } 
    printf("\n"); 
     
    return 0; 
} 