/**
 * Author: Xavier Niu
 */

#include <iostream>

typedef struct LinkNode {
    int data;
    struct LinkNode *link;
} LinkNode, *LinkList;

void init(LinkList head, int n) {
    LinkList prev = head;
    for (int i=0; i<n; i++) {
        LinkList ln = (LinkList)malloc(sizeof(LinkNode));
        ln->data = i;
        ln->link = nullptr;
        prev->link = ln;
        prev = ln;
    }
}

void traverse(LinkList head) {
    printf("results from performing traverse(): ");
    LinkList p = head;
    while (p->link) {
        printf("%d  ", p->link->data);
        p = p->link;
    }
    printf("\n");
}

int my_answer(LinkList head, int k) {
    LinkList p = head;
    // get length of link list
    int counter = 0;
    while (p->link) {
        p = p->link;
        counter++;
    }
    int index = counter - k;
    // reset and get value
    counter = 0;
    p = head;
    while (p->link) {
        if (counter == index) {
            printf("data you want to search by my_answer(): %d\n", p->link->data);
            return 1;
        }
        p = p->link;
        counter++;
    }
    printf("no data found!\n");
    return 0;
}

int standard_answer(LinkList head, int k) {
    LinkList p = head->link, q = head->link;
    int count = 0;
    while (p != nullptr) {
        if (count < k) count++;
        else q = q->link;
        p = p->link;
    }

    if (count < k) {
        printf("no data found!\n");
        return 0;
    } else {
        printf("data you want to search by standard_answer(): %d\n", q->data);
        return 1;
    }
}

int main() {

    LinkList head = (LinkList)malloc(sizeof(LinkNode));
    init(head, 10);
    traverse(head);

    my_answer(head, 1);
    standard_answer(head, 1);

    my_answer(head, 10);
    standard_answer(head, 10);

    my_answer(head, 11);
    standard_answer(head, 11);

    return 0;
}
