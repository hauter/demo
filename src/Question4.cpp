/*
 *ʵ��һ�����������ַ����е�ÿ���ո��滻��"%20".
 *��ԭ�ַ����Ͻ��в���, �ַ�������ռ��㹻.
 */
#include <iostream>
using namespace  std;
//lenΪ�ַ���������
void ReplaceBlank (char *str, int len)
{
    if (str == NULL || len <= 0) return;
    int i, num = 0;
    //ͳ�ƿո����
    for (i = 0; str[i] != '\0'; ++i)
    {
        if (str[i] == ' ')
            ++num;
    }//for
    int o = i -1;               //���������һ���ַ�λ��
    int n = i + 2 * num - 1;    //���������һ���ַ���λ��
    for (; o != n; --o, --n)
    {
        if (str[o] == ' ')
        {
            str[n] = '0';
            str[--n] = '2';
            str[--n] = '%';
        }
        else
            str[n] = str[o];
    }

}

int mainQ4 (void)
{
    char a[100] = " we are happy! ";
    ReplaceBlank(a, 100);
    cout << a << endl;
    return 0;
}
