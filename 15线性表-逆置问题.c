#include <stdio.h>
#include <stdlib.h>

typedef struct LNode
{
    int data;
    struct LNode *next;
}LNode;
// 顺序表逆置算法(left-right子区间)
void reverseArray(int arr[], int left, int right)
{
    while(left < right)
    {
        int temp = arr[left];
        arr[left] = arr[right];
        arr[right] = temp;
        left++;
        right--;
    }
}
// 就地逆置单链表
LNode* reverseList(LNode *L)
{
    LNode *p = L->next;
    LNode *next;
    L->next = NULL;
    while(p)
    {
        next = p->next;
        p->next = L->next;
        L->next = p;
        p = next;
    }
    return L;
}
int main()
{
    int arr[10];
    for(int i = 0; i < 10; ++i)
    {
        arr[i] = i;
    }
    // 将一长度为n的数组的前端k(k<n)个元素逆序后移动到数组后端，要求原数组中数据不丢失，其余元素的位置无关紧要
    reverseArray(arr, 0, 9);
    for(int i = 0; i < 10; ++i)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
    for(int i = 0; i < 10; ++i)
    {
        arr[i] = i;
    }
    // 将一长度为n的数组的前端k(k<n)个元素保持原序移动到数组后端，要求原数组中数据不丢失，其余元素的位置无关紧要
    // 以k = 3为例
    reverseArray(arr, 0, 2);
    reverseArray(arr, 0, 9);
    for(int i = 0; i < 10; ++i)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
    for(int i = 0; i < 10; ++i)
    {
        arr[i] = i;
    }
    // 将数组中的元素循环左移p(0<p<n)个位置
    // 以p = 3为例
    reverseArray(arr, 0, 2);
    reverseArray(arr, 3, 9);
    reverseArray(arr, 0, 9);
    for(int i = 0; i < 10; ++i)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
    return 0;
}