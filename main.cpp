#pragma clang diagnostic push
#pragma ide diagnostic ignored "modernize-use-nullptr"
#pragma ide diagnostic ignored "cert-err34-c"
/**
 * 链表
 */

#include <iostream>

typedef int ElemType;

typedef struct LNode {
    ElemType data;
    struct LNode *next;
} LNode, *LinkList;

/**
 * 头插法建立单链表
 * @param L
 * @return
 */
LinkList List_HeadInsert(LinkList &L) {
    LNode *s;
    ElemType x;
    L = (LinkList)malloc(sizeof(LNode));    // 上面定义了LinkList为指针类型，这里就不需要改写为LinkList *了
    L->next = NULL;
    scanf("%d", &x);

    while (x != 9999) {
        s = (LNode *)malloc(sizeof(LNode));
        s->data = x;
        s->next = L->next;
        L->next = s;
        scanf("%d", &x);
    }
    return L;
}

int main() {
    LinkList L;

    std::cout << "请输入插入元素: \n";
    L = List_HeadInsert(L);

    return 0;
}
#pragma clang diagnostic pop