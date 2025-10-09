#include <stdio.h>
#define maxSize 10
// 顺序栈结构体
typedef struct
{
    int data[maxSize];
    int top;
}SqStack;
// 初始化栈
void initStack(SqStack *st)
{
    st->top = -1;
}
// 判断栈空
int isEmpty(SqStack *st)
{
    if(st->top == -1)
        return 1;
    else
        return 0;    
}
// 判断栈满
int isFull(SqStack *st)
{
    if(st->top == maxSize - 1)
        return 1;
    else
        return 0;
}
// 进栈
int push(SqStack *st, int x)
{
    if(isFull(st))
        return 0; // 栈满，入栈失败
    // 先移动栈顶指针，再入栈
    st->data[++st->top] = x;
    return 1;
}
// 出栈
int pop(SqStack *st, int *x)
{
    if(isEmpty(st))
        return 0; // 栈空，出栈失败
    // 先出栈，再移动栈顶指针
    *x = st->data[st->top--];
    return 1;
}

// 使用示例
int main() {
    SqStack s;
    int val;

    initStack(&s);

    printf("入栈:1 2 3\n");
    push(&s, 1);
    push(&s, 2);
    push(&s, 3);

    printf("出栈:");
    while (!isEmpty(&s)) {
        pop(&s, &val);
        printf("%d ", val);
    }
    printf("\n");

    return 0;
}