#include <stdio.h>
#define maxSize 50
typedef struct
{
    int data[maxSize];
    int length;
}SqList;
// 顺序表-查找指定元素位置
int findElem(SqList L, int e)
{
    int i;
    for(i = 0; i < L.length; ++i)
        if(e == L.data[i])
            return i;
    return -1;
}
// 顺序表-在指定位置插入元素
int insertElem(SqList *L, int p, int e)
{
    int i;
    if(p < 0 || p > L->length || L->length == maxSize)
        return 0;
    for(i = L->length - 1; i >= p; --i)
        L->data[i+1] = L->data[i];
    L->data[p] = e;
    ++(L->length);
    return 1;
}
// 顺序表-删除指定位置元素
int deleteElem(SqList *L, int p, int *e)
{
    int i;
    if(p < 0 || p > L->length - 1)
        return 0;
    *e = L->data[p];
    for(i = p; i < L->length - 1; ++i)
        L->data[i] = L->data[i+1];
    --(L->length);
    return 1;
}
// 顺序表-初始化算法
void initList(SqList *L)
{
    L->length = 0;
}
// 顺序表-求指定位置元素值
int getElem(SqList L, int p, int *e)
{
    if(p < 0 || p > L.length - 1)
        return 0;
    *e = L.data[p];
    return 1;
}
int main()
{
    SqList L;
    int i, j, e;
    for(i = 0; i < 5; ++i)
    {
        L.data[i] = i;
        L.length++; // 关键步骤
    }
    j = findElem(L, 3);
    printf("元素3的位置是%d\n", j);
    if(insertElem(&L, 3, 10))
        printf("插入后第3个位置的元素为%d\n", L.data[3]);
    if(deleteElem(&L, 3, &e))
        printf("删除的元素是%d\n", e);
    if(getElem(L, 3, &e))
        printf("删除后第3个位置的元素为%d\n", L.data[3]);

    return 0;
}