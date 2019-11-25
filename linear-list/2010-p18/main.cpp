/**
 * Author: Xavier Niu
 */

#include <iostream>

#define MaxSize 50

typedef struct {
    int length;
    int *data;
} SeqList, *SeqListPointer;

SeqList init(int size) {
    if (size > MaxSize) {
        printf("size you input is greater than MaxSize.\n");
    }
    SeqList a;
    a.length = size;
    a.data = (int *)malloc(sizeof(int) * size);
    for (int i = 0; i < size; i++) a.data[i] = i;
    return a;
}

void traverse(SeqList arr) {
    printf("traverse(): ");
    for (int i=0; i<arr.length; i++) {
        printf("%d  ", arr.data[i]);
    }
    printf("\n");
}

void traverse(SeqListPointer arr) {
    printf("traverse(): ");
    for (int i=0; i<arr->length; i++) {
        printf("%d  ", arr->data[i]);
    }
    printf("\n");
}

void reverse(SeqList &arr, int start, int end) {
    for (int i = 0; (i + start) <= ((start + end) / 2); i++) {
        int temp = arr.data[start+i];
        arr.data[start+i] = arr.data[end-i];
        arr.data[end-i] = temp;
    }
}

// my_answer() is correct!
void my_answer(SeqList &arr, int p) {
    if (p < 0 || p >= arr.length) {
        printf("p is an invalid value.\n");
        return;
    }
    // reverse all elements
    reverse(arr, 0, arr.length - 1);
    // reverse all elements between `0` and `arr.size - p - 1`
    reverse(arr, 0, arr.length - p - 1);
    // reverse all elements between `arr.size - p` and `arr.size - 1`
    reverse(arr, arr.length - p, arr.length - 1);
}

int main() {
    SeqList arr = init(10);
    traverse(arr);

    my_answer(arr, 4);
    traverse(arr);

    return 0;
}
