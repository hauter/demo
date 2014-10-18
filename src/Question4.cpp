/*
 *实现一个函数，把字符串中的每个空格替换成"%20".
 *在原字符串上进行操作, 字符串空余空间足够.
 */
#include <iostream>
using namespace  std;
//len为字符串总容量
void ReplaceBlank (char *str, int len)
{
    if (str == NULL || len <= 0) return;
    int i, num = 0;
    //统计空格个数
    for (i = 0; str[i] != '\0'; ++i)
    {
        if (str[i] == ' ')
            ++num;
    }//for
    int o = i -1;               //旧内容最后一个字符位置
    int n = i + 2 * num - 1;    //新内容最后一个字符的位置
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
