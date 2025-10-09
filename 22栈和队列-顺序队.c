#include <stdio.h>
#define maxSize 10
/**
由于顺序队会出现“假溢出”问题，在此采用改良版本——循环队列
**/
// 循环队列结构体
typedef struct
{
    int data[maxSize];
    int front; // 队首指针，指向队首元素
    int rear; // 队尾指针，指向队尾元素的下一个空位置
}SqQueue;
// 循环队列初始化
void initQueue(SqQueue *qu)
{
    qu->front = 0;
    qu->rear = 0;
}
// 判断队空
int isEmpty(SqQueue *qu)
{
    if(qu->rear == qu->front)
        return 1;
    else
        return 0;
}
// 判断队满
int isFull(SqQueue *qu)
{
    // 队满的条件：(rear + 1) % maxSize == front
    // 牺牲一个存储空间来区分空和满
    if((qu->rear + 1) % maxSize == qu->front)
        return 1;
    else
        return 0;
}
// 入队
int enQueue(SqQueue *qu, int x)
{
    if(isFull(qu))
        return 0; // 队满，入队失败
    qu->data[qu->rear] = x; // 元素放入队尾指针指向的空位置
    qu->rear = (qu->rear + 1) % maxSize; // 队尾指针循环后移
    return 1;
}
// 出队
int deQueue(SqQueue *qu, int *x)
{
    if(isEmpty(qu))
        return 0; // 队空，出队失败
    *x = qu->data[qu->front]; //从队首指针指向的位置取出元素
    qu->front = (qu->front + 1) % maxSize; // 队首指针循环后移
    return 1;
}
// 使用示例
int main() {
    SqQueue queue;
    int value;

    // 初始化队列
    initQueue(&queue);
    printf("✅ 循环队列已初始化。\n");

    // 测试队空
    if (isEmpty(&queue)) {
        printf("✅ 队列当前为空。\n");
    }

    // 入队操作
    printf("\n➡️  执行入队操作:\n");
    for (int i = 1; i <= 5; i++) {
        if (enQueue(&queue, i * 10)) {
            printf("元素 %d 入队成功。\n", i * 10);
        } else {
            printf("元素 %d 入队失败！队列已满。\n", i * 10);
        }
    }

    // 检查队列状态
    printf("\n队列状态: ");
    if (isEmpty(&queue)) printf("空");
    if (isFull(&queue)) printf("满");
    printf(" (front=%d, rear=%d)\n", queue.front, queue.rear);

    // 出队操作
    printf("\n⬅️  执行出队操作:\n");
    while (!isEmpty(&queue)) {
        if (deQueue(&queue, &value)) {
            printf("出队元素: %d\n", value);
        }
    }

    // 再次检查队列状态
    printf("\n出队完成后: ");
    if (isEmpty(&queue)) {
        printf("队列已空。\n");
    }

    // 尝试对空队列出队
    printf("\n尝试对空队列出队:\n");
    if (!deQueue(&queue, &value)) {
        printf("出队失败！队列为空。\n");
    }

    return 0;
}