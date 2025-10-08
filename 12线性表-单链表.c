#include <stdio.h>
#include <stdlib.h> // malloc()函数包括在其中

typedef struct LNode
{
    int data;
    struct LNode *next;
}LNode;

// 单链表操作——初始化
void initList(LNode **L)
{
    // L是一个二重指针，指向链表的头指针，而头指针指向链表的开始节点
    *L = (LNode*)malloc(sizeof(LNode));
    (*L)->next = NULL;
}
// 单链表操作——尾插法(已包括初始化)
void createListR(LNode **C, int a[], int n)
{
    LNode *s, *r;
    int i;
    *C = (LNode*)malloc(sizeof(LNode)); // 在此处修改了指针的值，所以需要传递二重指针
    (*C)->next = NULL; // 需使用(*C)因为->优先级高于*
    r = *C;
    for(i = 0; i < n; ++i)
    {
        s = (LNode*)malloc(sizeof(LNode));
        // 尾插法关键步骤
        s->data = a[i];
        r->next = s;
        r = r->next;
    }
    // 尾插法最终指向NULL
    r->next = NULL;
}
// 单链表操作——头插法(已包括初始化)
void createListF(LNode **C, int a[], int n)
{
    LNode *s;
    int i;
    *C = (LNode*)malloc(sizeof(LNode));
    (*C)->next = NULL;
    for(i = 0; i < n; ++i)
    {
        s = (LNode*)malloc(sizeof(LNode));
        s->data = a[i];
        s->next = (*C)->next;
        (*C)->next = s;
    }
}
// 单链表操作——按值查找
LNode* locateElem(LNode *L, int x)
{
    if(L == NULL) return NULL;
    LNode *p = L->next; // 直接从第一个数据结点开始
    while(p != NULL && p->data != x)
    {
        p = p->next;
    }
    return p; // 找到返回该结点指针，未找到返回NULL
}
// 单链表操作——按位查找
LNode* getElem(LNode *L, int i)
{
    if(L == NULL || i < 1) return NULL;
    LNode *p = L->next;
    int j = 1;
    while(p != NULL && j < i)
    {
        p = p->next;
        j++;
    }
    return (j == i) ? p : NULL;
}
// 单链表操作——按值删除
int deleteElem(LNode *L, int x)
{
    if(L == NULL || L->next == NULL)
    {
        return 0; // 空表，删除失败
    }
    LNode *p, *q;
    p = L;
    while(p->next != NULL && p->next->data != x)
    {
        p = p->next; // 关键是寻找前驱结点
    }
    if(p->next == NULL)
    {
        return 0; // 未找到值为x的结点
    }
    // 删除关键操作
    q = p->next;
    p->next = q->next;
    free(q);
    return 1;
}
// 单链表操作——按位删除
int eraseElem(LNode *L, int i)
{
    if(L == NULL || L->next == NULL || i < 1)
    {
        return 0;
    }
    LNode *p = L;
    int j = 0;
    while(p->next != NULL && j < i - 1)
    {
        // 依旧是寻找前驱节点
        p = p->next;
        j++;
    }
    if(j != i - 1 || p->next == NULL) // 防御性编程
    {
        return 0;
    }
    // 删除关键操作
    LNode *q = p->next;
    p->next = q->next;
    free(q);
    return 1;
}
// 单链表操作——打印
void printList(LNode *L) {
    if (!L || !L->next) {
        printf("(空)\n");
        return;
    }
    LNode *p = L->next;
    while (p) {
        printf("%d ", p->data);
        p = p->next;
    }
    printf("\n");
}
// 单链表操作——销毁
void destroyList(LNode **L) {
    LNode *p = *L;
    while (p) {
        LNode *temp = p;
        p = p->next;
        free(temp);
    }
    *L = NULL;
}
// 使用示例
int main() {
    int arr[] = {1, 2, 3, 4, 5};
    int n = sizeof(arr) / sizeof(arr[0]);
    LNode *L = NULL;

    // 1.尾插法建表
    createListR(&L, arr, n);
    printf("尾插法建表: ");
    printList(L);  // 应输出: 1 2 3 4 5

    // 2.按值查找
    LNode *p = locateElem(L, 3);
    printf("查找值 3: %s\n", p ? "找到" : "未找到");

    // 3.按位置查找
    LNode *q = getElem(L, 2);
    printf("第2个元素: %s\n", q ? "存在" : "不存在");

    // 4.按值删除
    deleteElem(L, 3);
    printf("删除值 3 后: ");
    printList(L);  // 应输出: 1 2 4 5

    // 5.按位置删除
    eraseElem(L, 1);
    printf("删除第1个元素后: ");
    printList(L);  // 应输出: 2 4 5

    // 6.头插法重建
    destroyList(&L);
    createListF(&L, arr, n);
    printf("头插法建表: ");
    printList(L);  // 应输出: 5 4 3 2 1

    destroyList(&L);
    return 0;
}