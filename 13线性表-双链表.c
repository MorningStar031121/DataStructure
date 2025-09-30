#include <stdio.h>
#include <stdlib.h>

typedef struct DLNode
{
    int data;
    struct DLNode *prior, *next;
}DLNode;

// 双链表操作——尾插法
void createListR(DLNode **L, int a[], int n)
{
    DLNode *s, *r;
    int i;
    *L = (DLNode*)malloc(sizeof(DLNode));
    (*L)->prior = NULL;
    (*L)->next = NULL;
    r = *L;
    for(i = 0; i < n; ++i)
    {
        s = (DLNode*)malloc(sizeof(DLNode));
        s->data = a[i];
        r->next = s;
        s->prior = r;
        r = s;
    }
    r->next = NULL;
}
// 双链表操作——查找结点
DLNode* locateElem(DLNode *L, int x)
{
    if(L == NULL) return NULL;
    DLNode *p = L->next;
    while(p != NULL && p->data != x)
    {
        p = p->next;
    }
    return p;
}
// 双链表操作——插入结点
int insertElem(DLNode *L, int i, int x)
{
    if(L == NULL || i < 1) return 0;
    DLNode *p = L;
    int j = 1;
    while(p != NULL && j < i)
    {
        p = p->next;
        j++;
    }
    if(p == NULL) return 0;
    DLNode *s = (DLNode*)malloc(sizeof(DLNode));
    s->data = x;
    s->next = p->next;
    p->next = s;
    s->prior = p;
    if(s->next != NULL)
        s->next->prior = s;
    return 1;
}
// 双链表操作——删除结点
int deleteElem(DLNode *L, int i)
{
    if(L == NULL || i < 1) return 0;
    DLNode *p = L;
    int j = 1;
    while(p != NULL && j < i)
    {
        p = p->next;
        j++;
    }
    if(p == NULL || p->next == NULL) return 0;
    DLNode *q = p->next;
    p->next = q->next;
    if(p->next != NULL)
        p->next->prior = p;
    free(q);
    return 1;
}
// 打印整个链表（从头结点开始，标出序号）
void printList(DLNode *L) {
    if (!L) { printf("NULL list\n"); return; }
    DLNode *p = L;
    int idx = 1;
    printf("链表（头结点为第1个）:\n");
    while (p) {
        printf("  结点%d: data=%d\n", idx++, p->data);
        p = p->next;
    }
    printf("\n");
}
// 使用示例
int main()
{
    DLNode *L;
    int arr[] = {10, 20, 30};
    
    // 1. 创建链表：头结点 + [10, 20, 30]
    createListR(&L, arr, 3);
    printf("1. 创建链表后:\n");
    printList(L);

    // 2. 在第1个结点（头结点）后插入 5
    insertElem(L, 1, 5);
    printf("2. 在第1个结点后插入 5:\n");
    printList(L);

    // 3. 在第3个结点（当前是10）后插入 15
    insertElem(L, 3, 15);
    printf("3. 在第3个结点后插入 15:\n");
    printList(L);

    // 4. 删除第2个结点的后继（即删除第3个结点，值为10）
    deleteElem(L, 2);
    printf("4. 删除第2个结点的后继（删除10）:\n");
    printList(L);

    // 5. 查找 15
    if (locateElem(L, 15))
        printf("5. 成功找到值为 15 的结点！\n\n");
    else
        printf("5. 未找到 15\n\n");
    return 0;
}