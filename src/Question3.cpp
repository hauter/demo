/*在一个二维数组中， 每一行都按照从左到右递增的顺序排序，每一列都按照从上到下递增
 * 的顺序排序。请完成一个函数，输入这样的一个二维数组和一个整数，判断数组中是否
 * 含有该整数。
 */

#include <iostream>
using namespace std;

bool Check (int *a, int rows, int cols, int num)
{
    if (a == NULL) return false;
    int rlow = 0, rhigh = rows - 1;
    int clow = 0, chigh = cols - 1;
    //缩写列范围
    while (rlow <= rhigh && clow <= chigh)
    {
        //方块右上角
        int p1 = rlow * cols + chigh;
        if (a[p1] == num) return true;
        else if (a[p1] > num) --chigh;
        else ++rlow;

        //方块左下角
        int p2 = rhigh * cols + clow;
        if (a[p2] == num ) return true;
        else if (a[p2] > num) --rhigh;
        else ++clow;
    }
    return false;
}

int mainQ3 (void)
{
    int a[4][5] = {
        {1, 2,  8,  9,  14 },
        {2, 4,  9,  12, 17},
        {4, 7,  10, 13, 19},
        {6, 8,  11, 15, 21}};
    if (Check(*a, 4, 5,10 ))
        cout << "yes";
    else cout << "no";
    return 0;
}

