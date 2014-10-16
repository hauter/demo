//冒泡排序
#include <iostream>
using namespace std;

void BubbleSort(int a[], int n)
{
    int count1 = 0, count2 = 2;
    int flag;
    for (int i = n; i > 0; --i)
    {
        flag = 0;
        for (int j = 0; j < n - 1; ++j)
        {
            ++count1;

            if ( a[j] > a[j + 1] )
            {
                flag = 1;
                ++count2;
                int temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
            }
        }
        if (!flag) break;
    }
    cout << count1 << "   " << count2 << endl;
}

int main3 (void)
{
    int a[] = {21, 3, 12, 0, 5, 3, 18, 22, 30, 8, 6 };
    int length = sizeof(a) / sizeof(int);
    BubbleSort(a, length);
    for (int i = 0; i < length; ++i)
    {
        cout << a[i] << "  ";
    }
    return 0;
}
