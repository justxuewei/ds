/**
 * Author: Xavier Niu
 */

#include <iostream>

#define SeqLength 5

typedef struct {
    int length;
    int data[SeqLength];
} SeqList, *SeqListPointer;

void init(SeqList &a, SeqList &b) {
    SeqList _a = {5, {11, 13, 15, 17, 19}};
    SeqList _b = {5, {2, 4, 6, 8, 20}};
    a = _a;
    b = _b;
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

/**
 * time complexity: n
 */
int my_answer(SeqList a, SeqList b) {
    int mid = (a.length + b.length) / 2;
    int index_a = 0, index_b = 0;
    for (int i = 1; i < mid; i++) {
        if (a.data[index_a] >= b.data[index_b]) index_b++;
        else index_a++;
    }
    return a.data[index_a] < b.data[index_b] ? a.data[index_a] : b.data[index_b];
}

/**
 * time complexity: log(n)
 */
int standard_answer(SeqList a, SeqList b) {
    int s1 = 0, d1 = a.length - 1, m1, s2 = 0, d2 = b.length - 1, m2;
    while (s1 != d1 || s2 != d2) {
        m1 = (s1 + d1) / 2;
        m2 = (s2 + d2) / 2;
        if (a.data[m1] == b.data[m2]) return a.data[m1]; // the midians from a and b are equal
        // the quantity of items that be discarded must be equal
        if (a.data[m1] < b.data[m2]) { // throw the elements that smaller than median of `a` and greater than median of `b` away
            if ((s1 + d1) % 2 == 0) {
                s1 = m1;
                d2 = m2;
            } else {
                s1 = m1 + 1;
                d2 = m2;
            }
        } else { // throw the elements that greater than median of `a` and smaller than median of `b` away
            if ((s2 + d2) % 2 == 0) {
                d1 = m1;
                s2 = m2;
            } else {
                d1 = m1;
                s2 = m2 + 1;
            }
        }
    }
    return a.data[s1] < b.data[s2] ? a.data[s1] : b.data[s2];
}

int main() {

    SeqList a, b;
    init(a, b);
    traverse(a);
    traverse(b);

    int answer = my_answer(a, b);
    printf("median by my_answer(): %d\n", answer);
    answer = standard_answer(a, b);
    printf("median by standard_answer(): %d\n", answer);

    return 0;
}
