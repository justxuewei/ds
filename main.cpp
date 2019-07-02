#pragma clang diagnostic push
#pragma ide diagnostic ignored "hicpp-use-auto"
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

/**
 * 尾插法建立单链表
 * @param L
 * @return
 */
LinkList List_TailInsert(LinkList &L) {
    ElemType x;
    L = (LinkList)malloc(sizeof(LNode));
    LNode *s, *r = L;   // r为尾结点指针
    scanf("%d", &x);
    L->next = NULL;

    while (x != 9999) {
        s = (LNode *)malloc(sizeof(LNode));
        s->data = x;
        r->next = s;
        r = s;
        scanf("%d", &x);
    }

    r->next = NULL;
    return L;
}

/**
 * 根据序号获取链表元素
 * @param L
 * @param i i为位置而非索引，例如1, 2, 3, ...
 * @return
 */
LNode *GetElem(LinkList L, int i) {
    if (i < 0) {
        return NULL;
    }

    LNode *p = L;
    int x = 0;
    while (x < i && p != NULL) {
        p = p->next;
        x++;
    }

    return p;
}

/**
 * 按值查找表结点
 * @param L
 * @param e
 * @return
 */
LNode *LocateElem(LinkList L, ElemType e) {
    LNode *p = L->next;
    while (p != NULL && e != p->data) {
        p = p->next;
    }
    return p;
}

/**
 * 在第i个位置前面插入一个结点
 * @param L
 * @param i
 * @param e
 */
void ListInsert(LinkList &L, int i, ElemType e) {
    LNode *p = GetElem(L, i-1); // 这里是i-1的意思是插入在第i个结点的前面
    if (p == NULL) return;
    LNode *s = (LNode *)malloc(sizeof(LNode));
    s->data = e;
    s->next = p->next;
    p->next = s;
}

/**
 * 在该结点的前面插入一个值
 * @param i
 * @param e
 */
void ListInsertWithINode(LNode *i, ElemType e) {
    LNode *p = (LNode *)malloc(sizeof(LNode));  // 与后插法一致
    p->next = i->next;
    i->next = p;
    p->data = i->data;  // 前后数据互换实现前插，时间复杂度O(1)
    i->data = e;
}

/**
 * 删除第第i个位置的结点
 * @param L
 * @param i
 * @param e
 */
void ListDelete(LinkList &L, int i, ElemType &e) {
    LNode *p = GetElem(L, i-1); // 同ListInsert
    LNode *q = p->next;
    p->next = q->next;
    e = q->data;
    free(q);
}

/**
 * 删除该结点i，原理同ListInsertWithINode
 * @param p
 * @param e
 */
void ListDeleteWithINode(LNode *p, ElemType &e) {
    e = p->data;
    LNode *q = p->next;
    p->data = q->data;
    p->next = q->next;
    free(q);
}

int main() {
    LinkList L;

    std::cout << "请输入插入元素: \n";
//    L = List_HeadInsert(L);
    L = List_TailInsert(L);
    LNode *i2 = GetElem(L, 2);
    std::cout << "第二项数据为: " << i2->data << std::endl;

    return 0;
}
#pragma clang diagnostic pop