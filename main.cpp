#pragma clang diagnostic push
#pragma ide diagnostic ignored "hicpp-use-auto"
#pragma ide diagnostic ignored "modernize-use-nullptr"
#pragma ide diagnostic ignored "cert-err34-c"
/**
 * 顺序表
 */

#define MAX_SIZE 100

#include <iostream>

typedef int ElemType;

typedef struct {
    ElemType *data;
    int MaxSize, length;
} SeqList;

/**
 * 初始化顺序表
 * @return
 */
SeqList InitList() {
    ElemType *arr = (ElemType *)malloc(sizeof(SeqList) * MAX_SIZE); // 动态分配
    SeqList seqList;    // 初始化相关参数
    seqList.MaxSize = MAX_SIZE;
    seqList.length = 0;
    seqList.data = arr;
    ElemType x;
    scanf("%d", &x);
    for (; seqList.length < seqList.MaxSize && x != 9999; seqList.length++) {
        seqList.data[seqList.length] = x;
        scanf("%d", &x);
    }
    return seqList;
}

/**
 * 插入操作
 * 需要着重理清位序与索引之间的关系，推荐画图
 * @param L
 * @param i 位序而非下标
 * @param e 插入元素
 * @return 是否插入成功
 */
bool ListInsert(SeqList &L, int i, ElemType e) {
    // 检查输入i是够合法
    // "L.length + 1"表明的是当前已有的数据最大位序，这里不用MaxSize
    if (i < 1 || i > L.length + 1) return false;
    if (L.length >= L.MaxSize) return false;    // 检查空间是否已满
    for (int j = L.length; j >= i; j--) // 从后往前遍历可以省去再次遍历移动的时间
        L.data[j] = L.data[j-1];
    L.data[i-1] = e;
    L.length++; // 表长度+1不要忘了
    return true;
}

/**
 * 删除操作，同ListInsert
 * @param L
 * @param i
 * @param e
 * @return
 */
bool ListDelete(SeqList &L, int i, ElemType &e) {
    if (i < 1 || i >= L.length + 1) return false;   // 检查i是否合法
    if (L.length <= 0) return false;    // 如果链表为空则无法删除
    e = L.data[i - 1];  // 将原始数据保存
    for (int j = i; j < L.length; j++)
        L.data[j - 1] = L.data[j];
    L.length--;
    return true;
}

/**
 * 按值查找
 * @param L
 * @param e
 * @return 返回位序
 */
int LocateElem(SeqList L, ElemType e) {
    for (int i = 0; i < L.length; i++)
        if (e == L.data[i])
            return i + 1;   // 返回的是位序
    return 0;
}

/**
 * [Chapter 2.2 综合题6] 有序表去重
 * @param L
 * @return
 */
bool OrderedListDeduplicate(SeqList &L) {
    if (L.length < 1) return false;
    int k = 0;
    ElemType e = L.data[0];
    for (int i = 1; i < L.length; i++) {
        if (e != L.data[i]) {
            e = L.data[i];
            L.data[i-k] = L.data[i];
        } else {
            k++;
        }
    }
    L.length -= k;
    return true;
}

/**
 * [Chapter 2.2 综合题7] 将有序表合并为一张新表
 * @param A
 * @param B
 * @param C
 * @return
 */
bool OrderedListMerge(SeqList A, SeqList B, SeqList &C) {
    if (A.length + B.length > C.length) return false;   // 检查C是否有能力装入全部的数据
    int i = 0, j = 0, k = 0;
    while (i<A.length && j<B.length) {
        if (A.data[i] <= B.data[j])
            C.data[k++] = A.data[i++];
        else
            C.data[k++] = B.data[j++];
    }
    while (i<A.length) {
        C.data[k++] = A.data[i++];
    }
    while (j<B.length) {
        C.data[k++] = B.data[j++];
    }
    C.length = k;
    return true;
}

/**
 * 打印列表
 * @param L
 */
void ListPrint(SeqList L) {
    for (int i = 0; i < L.length; i++) {
        printf("%d\t", L.data[i]);
    }
    printf("\n");
}

int main() {

    printf("请输入顺序表序列（输入9999以停止）: \n");
    SeqList seqList = InitList();
    ListPrint(seqList);
    OrderedListDeduplicate(seqList);
    ListPrint(seqList);

    return 0;
}
#pragma clang diagnostic pop