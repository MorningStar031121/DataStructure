#include <stdio.h>

void oneArray(int* arr, int size)
{
    arr[2] = 0;
    printf("传入函数的数组%ld\n", sizeof(arr));
}

void twoArray(int (*arr)[4], int rows)
{
    arr[2][2] = 0;
    printf("传入函数的数组%ld\n", sizeof(arr));
}
int main()
{
    int arr1[4] = {1, 1, 1, 1};
    int arr2[4][4] = {
        {1, 1, 1, 1}, {1, 1, 1, 1}, {1, 1, 1, 1}, {1, 1, 1, 1}
    };

    printf("一维数组更改前第3个元素为:%d\n", arr1[2]);
    printf("未传入函数的数组%ld\n", sizeof(arr1));
    oneArray(arr1, 4);
    printf("一维数组更改后第3个元素为:%d\n", arr1[2]);

    printf("二维数组更改前第3行第3列元素为:%d\n", arr2[2][2]);
    printf("未传入函数的数组%ld\n", sizeof(arr2));
    twoArray(arr2, 4);
    printf("二维数组更改后第3行第3列元素为:%d\n", arr2[2][2]);

    return 0;
}