#include <iostream>
using namespace std;
void AdjustDown (int a[], int t, int len)
{
    a[0] = a[t];
    for (int i = t * 2; i <= len; i *= 2)
    {
        if (i < len && a[i] < a[i + 1])
            ++i;
        if (a[0] < a[i])
        {
            a[t] = a[i];
            t = i;
        }
        else
            break;
    }//for
    a[t] = a[0];
}
void BuildMaxHeap (int a[], int len)
{
    for (int i = len / 2; i >= 0; --i)
    {
        //从 n / 2 ~ 0反复调整
        AdjustDown (a, i, len);
    }//for
}


void HeepSort (int a[], int len)
{
    BuildMaxHeap(a, len);
    for (int i = len; i > 1; --i)
    {
        //将最大的元素放到第i个位置
        int temp = a[1];
        a[1] = a[i];
        a[i] = temp;
        AdjustDown (a, 1, i - 1);
    }
}

int main (void)
{
    //a[0]不是序列的一部分,设置为空位
    int a[] = {-1, 21, 3, 12, 0, 5, 3, 18, 22, 30, 8, 6 };
    int length = sizeof(a) / sizeof(int) - 1;
    HeepSort(a, length);
    for (int i = 1; i <= length; ++i)
        cout << a[i] << "  ";
    return 0;
}
