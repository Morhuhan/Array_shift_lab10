#include <stdio.h>
#define N 10

void print_array(int* A, int size_a) {
    for(int i = 0; i < size_a; ++i) {
        printf(" %d ", A[i]);
    }
    printf("\n");
}

void read (int* A, FILE* f, int size_a) {
    for (int i = 0; i < size_a; i++) {
        fscanf (f, "%d", &A[i]);
    }
}

void left_shift(int* A, int size_a) {
    int tmp;
    tmp = A[0];  // Cycle shift to the left
    for(int i = 0; i < size_a-1; ++i)
        A[i] = A[i+1];
    A[size_a-1] = tmp;


}

void right_shift(int* A, int size_a) {
    int tmp;
    tmp = A[N-1];  // Cycle shift to the right
    for(int i = N-1; i > 0; --i)
        A[i] = A[i-1];
    A[0] = tmp;
}

void main(void) {

    FILE *f;
    int size_a = N;
    int A[size_a];
    int flag = 0;
    int number = 0;

    printf("What kind of array shift do you want to do?");
    printf("1 - Array shift to the left");
    printf("2 - Array shift to the right");
    scanf("%d", &flag);

    printf("How many numbers do you want to shift?");
    scanf("%d", &number);

    if (flag == 1) {
        for(int i = 0; i < number; i++) {
            left_shift(A, size_a);
        }
    }

    else {

        for(int i = 0; i < number; i++) {
        right_shift(A, size_a);
    }


    }


    f = fopen ("file.txt", "r");  // Чтение чисел из файла в массив B
    read(A, f, size_a);
    fclose(f);




    print_array(A, size_a);
}