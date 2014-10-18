#include <stdio.h>

int Compare (char *str1, char *str2, int len1, int len2)
{
    int i;
    for (i = 0; i < len1 && i < len2; ++i)
    {
        if (str1[i] < str2[i]) return -1;
        else if (str1[i] > str2[i]) return 1;
    }
    if (len1 < len2) return -1;
    else if (len1 > len2) return 1;
    else return 0;
}


int main()
{
    char a[] = "abcdefg";
    char b[] = "abcdefga";
    int r = Compare(a, b, 7, 8);
    printf("%d\n", r);
    return 0;
}

