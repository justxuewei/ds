/**
 * Author: Xavier Niu
 */

#include <iostream>

#define MaxSize 50

typedef struct {
    int size;
    int *data;
} Array;

Array init(int size) {
    if (size > MaxSize) {
        printf("size you input is greater than MaxSize.\n");
    }
    Array a;
    a.size = size;
    a.data = (int *)malloc(sizeof(int) * size);
    for (int i = 0; i < size; i++) a.data[i] = i;
    return a;
}

void traverse(Array arr) {
    printf("traverse(): ");
    for (int i=0; i<arr.size; i++) {
        printf("%d  ", arr.data[i]);
    }
    printf("\n");
}

void reverse(Array &arr, int start, int end) {
    for (int i = 0; (i + start) <= ((start + end) / 2); i++) {
        int temp = arr.data[start+i];
        arr.data[start+i] = arr.data[end-i];
        arr.data[end-i] = temp;
    }
}

// my_answer() is correct!
void my_answer(Array &arr, int p) {
    if (p < 0 || p >= arr.size) {
        printf("p is an invalid value.\n");
        return;
    }
    // reverse all elements
    reverse(arr, 0, arr.size - 1);
    // reverse all elements between `0` and `arr.size - p - 1`
    reverse(arr, 0, arr.size - p - 1);
    // reverse all elements between `arr.size - p` and `arr.size - 1`
    reverse(arr, arr.size - p, arr.size - 1);
}

int main() {
    Array arr = init(10);
    traverse(arr);

    my_answer(arr, 4);
    traverse(arr);

    return 0;
}
