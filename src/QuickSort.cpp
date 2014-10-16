//快速排序
//low 和 high的位置交替成为坑，并用对方舍弃的数来填补
#include <iostream>
using namespace std;

int Partition (int a[], int low, int high)
{
    //在low先挖一个坑
    int pivot = a[low];
    while (low < high)
    {
        //定位到比pivot小的位置
        while (low < high && pivot <= a[high] )
            --high;
        a[low] = a[high];
        //定位到比pivot大的位置
        while (low < high && a[low] <= pivot)
            ++low;
        a[high] = a[low];
    }
    //将pivot填补的最后一个坑
    a[low] = pivot;

    return low;
}

void QuickSort (int a[], int low, int high)
{
    if (low < high)
    {
        int pivotPos = Partition(a, low, high);
        QuickSort (a, low, pivotPos - 1);
        QuickSort (a, pivotPos + 1, high);
    }
}


int main6 (void)
{
    int a[] = {21, 3, 12, 0, 5, 3, 18, 22, 30, 8, 6};
    int length = sizeof(a) / sizeof(int);
    QuickSort(a, 0, length - 1);
    for (int i = 0; i < length; ++i)
        cout << a[i] << "  ";
    return 0;
}
