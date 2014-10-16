//插入排序
#include <iostream>
using namespace std;
void InsertSort(int a[], int n)
{
    int i, j, temp;
    for (i = 1; i < n; ++i)
    {
        if (a[i - 1] > a[i])
        {
            temp = a[i];    //复制给哨兵
            //将前边的有序数后移
            for (j = i - 1; j >= 0; --j)
            {
                if (temp > a[j])
                    break;
                a[j + 1] = a[j];
            }
            a[j + 1] = temp;
        }
    }
}


int main4 (void)
{
    int a[] = {21, 3, 12, 0, 5, 3, 18, 22, 30, 8, 6 };
    int length = sizeof(a) / sizeof(int);
    InsertSort(a, length);
    for (int i = 0; i < length; ++i)
        cout << a[i] << "  ";
    return 0;
}
