#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#define array_size 10
#define max_array_value 99



void autocomplite(int *array, int max_value, int length);
void printarray(int *array, int length);
void swap(int *num_a, int *num_b);
int divide(int *array, int left_index, int right_index);
void quickSort(int *array, int init, int end);

int main() {

    int numbers[array_size];

    autocomplite(numbers, max_array_value, array_size);
    printarray(numbers, array_size);

    quickSort(numbers, 0, array_size - 1);
    printarray(numbers, array_size);

    return 0;
}

void autocomplite(int *array, int max_value, int length) {
    int i;
    
    srand(time(NULL));

    for (i=0; i < length; i++)
        *(array + i) = rand() % max_value + 1;
}

void printarray(int *array, int length) {
    int i;

    for (i=0; i < length; i++) {
        if (i % 5 == 0)
            printf("\n");
        printf("%d\t", *(array + i));
    }
    printf("\n");
}

void swap(int *num_a, int *num_b) {
    // Irá trocar um valor pelo outro invertendo-os
    int temp = *num_a;

    *num_a = *num_b;
    *num_b = temp;
}

int divide(int *array, int left_index, int right_index) {
    int pivot = (array[left_index] + array[right_index] + array[(left_index + right_index) / 2]) / 3;

   while (left_index < right_index) {
        while (left_index < right_index && array[left_index] <= pivot) {
            left_index++;
        }
        while (left_index < right_index && array[right_index] > pivot) {
            right_index--;
        }
        swap(&array[left_index], &array[right_index]);
    }

    return left_index;
}

void quickSort(int *array, int init, int end) {
    if (init < end) {
        int medium_pos = divide(array, init, end);
        quickSort(array, init, medium_pos - 1);
        quickSort(array, medium_pos, end);

    }
}