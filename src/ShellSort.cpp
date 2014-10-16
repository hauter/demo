//希尔排序
#include <iostream>
using namespace std;

void ShellSort (int a[], int n)
{
    int temp;
    for (int d = n / 2; d >= 1; d /= 2)
    {
        for (int i = d; i < n; i += d)
        {
            if (a[i - d] > a[i])
            {
                temp = a[i];
                int j;
                for ( j = i - d; j >= 0; j -= d)
                {
                    if (a[j] < temp)
                        break;
                    a[j + d] = a[j];
                }
                a[j + d] = temp;
            }
        }
    }
}

int main5 (void)
{
    int a[] = {21, 3, 12, 0, 5, 3, 18, 22, 30, 8, 6 };
    int length = sizeof(a) / sizeof(int);
    ShellSort(a, length);
    for (int i = 0; i < length; ++i)
        cout << a[i] << "  ";
    return 0;
}
