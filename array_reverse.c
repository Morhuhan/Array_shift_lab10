#include <stdio.h>
#define N 10

void print_array(int A[])
{
    for(int i = 0; i < N; ++i)
        printf(" %d ", A[i]);
    printf("\n");
}

int main() {

    FILE *f;
    int i_tmp = 0;
    int A[N];
    int temp;
    
    
    f = fopen ("file.txt", "r");  // находим кол-во ненулевых элементов
    for (int i = 0; i < N; i++) {
        int a;
        a = fscanf (f, "%d", &A[i]);
        if (a < 0) {
            temp = i;  // сохраняем номер первого "пустого" элемента в переменную temp
            break;
        }
    }
    fclose(f);
    
    f = fopen ("file.txt", "r");  // Чтение чисел из файла в массив B
        for (int i = 0; i < N; i++) {
            if (i_tmp == temp) {
                fseek (f, 0, SEEK_SET); // Сдвигаем указатель в начало файла каждые tmp итераций
                i_tmp = 0;              // Обнуляем счетчик
            }
            fscanf (f, "%d", &A[i]);
            i_tmp++;
        }
    fclose(f);
    
    int tmp;

    tmp = A[0];  // Cycle shift to the left
    for(int i = 0; i < N-1; ++i)
        A[i] = A[i+1];
    A[N-1] = tmp;
    print_array(A);

    tmp = A[N-1];  // Cycle shift to the right
    for(int i = N-1; i > 0; --i)
        A[i] = A[i-1];
    A[0] = tmp;
    print_array(A);

    return 0;
}