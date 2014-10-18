/*��һ����ά�����У� ÿһ�ж����մ����ҵ�����˳������ÿһ�ж����մ��ϵ��µ���
 * ��˳�����������һ������������������һ����ά�����һ���������ж��������Ƿ�
 * ���и�������
 */

#include <iostream>
using namespace std;

bool Check (int *a, int rows, int cols, int num)
{
    if (a == NULL) return false;
    int rlow = 0, rhigh = rows - 1;
    int clow = 0, chigh = cols - 1;
    //��д�з�Χ
    while (rlow <= rhigh && clow <= chigh)
    {
        //�������Ͻ�
        int p1 = rlow * cols + chigh;
        if (a[p1] == num) return true;
        else if (a[p1] > num) --chigh;
        else ++rlow;

        //�������½�
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

