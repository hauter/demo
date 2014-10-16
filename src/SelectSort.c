#include <stdio.h>

//选择排序
void SelectSort (int a[], int n)
{
    int i, j, min, temp, count1 = 0, count2 = 0;
    for ( i = 0; i < n; ++i )
    {
        min = i;
        for ( j = i + 1; j < n; ++j )
        {
            ++count1;
            if ( a[min] > a[j] )
            {
                min = j;
            }
        }
        if ( min != i)
        {
            ++count2;
            temp = a[i];
            a[i] = a[min];
            a[min] = temp;
        }
    }
    printf("%d   %d\n", count1, count2);

}

int main2 (void)
{
    int a[] = {21, 3, 12, 0, 5, 3, 18, 22, 30, 8, 6 };
    int i, length  = sizeof(a) / sizeof(int);
    SelectSort(a, length);
    for (i = 0; i < length; ++i)
    {
        printf("%d ", a[i]);
    }
    return 0;
}













