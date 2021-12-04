#include <stdio.h>
#define N 10

void print_array(int* A, int size_a) {
    for(int i = 0; i < size_a; ++i) {
        printf("%d ", A[i]);
    }
    printf("\n");
}

void read(int* A, FILE* f, int size_a) {
    for (int i = 0; i < size_a; i++) {
        fscanf(f, "%d", &A[i]);
    }
}

void left_shift(int* A, int size_a) {
    int tmp;
    tmp = A[0];  
    for(int i = 0; i < size_a-1; i++) {
        A[i] = A[i+1];
    }    
    A[size_a-1] = tmp;
}

void right_shift(int* A, int size_a) {
    int tmp;
    tmp = A[size_a-1];  
    for(int i = size_a-1; i > 0; i--) {
        A[i] = A[i-1];
    }
    A[0] = tmp;
}

void main(void) {
    FILE *f;
    int size_a = N;
    int A[size_a];
    int flag = 0;
    int number = 0;
    int again = 1;
    while (again == 1) {
        printf("What kind of array shift do you want to do?\n");
        printf("1 - Array shift to the left\n");
        printf("2 - Array shift to the right\n");
        scanf("%d", &flag);
        printf("How many numbers do you want to shift?\n");
        scanf("%d", &number);
        f = fopen ("file.txt", "r");  // Чтение чисел из файла в массив B
        read(A, f, size_a);
        fclose(f);
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
        print_array(A, size_a);
        printf("Do you want to shift again?\n");
        printf("1 - yes\n");
        printf("0 - no\n");
        scanf("%d", &again);
    }
}