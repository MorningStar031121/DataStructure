#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node *next;
}Node;

// 使用循环单链表解决约瑟夫环问题
void josehusLinkList(int n, int m)
{
    if (n < 1 || m < 1) return;
    // 创建链表
    int i;
    Node *head = (Node*)malloc(sizeof(Node));
    head->data = 1;
    Node *curr; // 用以标识当前数到的人，在创建链表时充当新结点的指针
    Node *prev = head; // 用以标识curr的前驱结点，在创建链表时充当链表的尾端指针
    for(i = 2; i <= n; ++i)
    {
        curr = (Node*)malloc(sizeof(Node));
        curr->data = i;
        prev->next = curr;
        prev = curr;
    }
    curr->next = head; // 将最后一个结点的指针域指向头结点，构成循环链表
    printf("出列顺序：");
    // 解决约瑟夫环问题
    prev = curr;
    curr = head; // 初始化prev与curr的正确位置
    while(curr->next != curr)
    {
        // 报数m位，curr应移动m-1位，prev始终在curr前面
        for(i = 1; i < m; ++i)
        {
            prev = curr;
            curr = curr->next;
        }
        // 删除报数到m的人
        printf("%d ", curr->data);
        prev->next = curr->next;
        free(curr);
        curr = prev->next;
    }
    // 剩最后一个人
    printf("%d\n", curr->data);
}
// 利用数组解决约瑟夫环问题
void josehusArray(int n, int m)
{
    if(n < 1 || m < 1) return;
    int *peo = (int*)malloc(n * sizeof(int));
    for(int i = 1; i <= n; ++i)
    {
        peo[i-1] = i;
    }
    // 解决约瑟夫环问题
    int remaining = n; // 剩余未出列的人
    int currentIndex = 0; // 当前报数的人在数组中的下标
    printf("出列顺序：");
    while(remaining > 0)
    {
        // 报数m个，下标加m-1个才能定位到报数到m的人
        int count = 0;
        while(count < m)
        {
            if(peo[currentIndex] != -1)
            {
                count++;
                if(count == m) break;
            }
            currentIndex = (currentIndex + 1) % n;
        }
        printf("%d ", peo[currentIndex]);
        peo[currentIndex] = -1;
        remaining--;

        currentIndex = (currentIndex + 1) % n; // 下一轮从出列的下一个人开始
    }
    printf("\n");
    free(peo);
}

int main()
{
    josehusArray(5, 3);
    return 0;
}