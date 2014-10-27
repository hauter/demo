/*
 *configure file reader and writter
 * 2014.10.25 written by Ziqiang Sun
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "cfg_op.h"


int GetcfgItem(char *fileName, char *keyName, char *value)
{
    int rv = 0, isFound = 0;
    FILE *fp = NULL;
    char lineBuff[LINEMAXLEN];
    char *pTmp = NULL, *pBegin = NULL, *pEnd = NULL;
    if (fileName == NULL || keyName == NULL || value == NULL)
    {
        rv = -1;
        printf("GetcfgItem() err. param err \n");
        goto End;
    }
    //open file
    fp = fopen(fileName, "r");
    if (fp == NULL)
    {
        rv = -2;
        printf("fopen() err. \n");
        goto End;
    }
    //read file
    while (!feof(fp))
    {
        memset(lineBuff, 0, sizeof(lineBuff));
        pTmp = fgets(lineBuff, LINEMAXLEN, fp);
        if (pTmp = NULL)
        {
            break;
        }
        //check if this line is configure line
        if (!strchr(lineBuff, '='))
            continue;
        //check if this line contain the key
        if (!strstr(lineBuff, keyName))
            continue;
        //ok, got it. make pTmp go to right of '='
        isFound = 1;
        pTmp = strchr(lineBuff, '=') + 1;
        while(1)
        {
            if (*pTmp == ' ')
            {
                pTmp ++;
            }
            else
            {
                pBegin = pTmp;
                if (*pBegin == '\n')
                {
                    printf("key: %s, no value \n", keyName);
                    goto End;
                }
                break;
            }
        }
        while (1)
        {
            if (*pTmp == '\n' || *pTmp == ' ')
            {
                break;
            }
            else
            {
                pTmp ++;
            }
        }
        pEnd = pTmp;
        memcpy(value, pBegin, pEnd - pBegin);
        value[pEnd - pBegin] = '\0';
        break;
    }
    if (isFound == 0)
    {
        rv = 1;
        printf("not found key: %s\n", keyName);
    }

End:
    if (fp != NULL)
    {
        fclose(fp);
    }
    return rv;

}


int WritecfgItem(char *fileName, char *keyName, char *value)
{
    int rv = 0, isContain = 0;
    long length = 0;
    FILE *fp = NULL;
    char lineBuff[LINEMAXLEN], fileBuff[1024 * 8];
    char *pTmp = NULL;
    if (fileName == NULL || keyName == NULL || value == NULL)
    {
        printf("WritecfgItem() err. param err \n");
        rv = -1;
        goto End;
    }
    fp = fopen(fileName, "r");
    if (fp == NULL)
    {
        printf("WritecfgItem() err.fopen() err. \n");
        rv = -2;
        goto End;
    }
    fseek(fp, 0L, SEEK_END);
    length = ftell(fp);
    fseek(fp, 0L, SEEK_SET);
    if (length > 8 * 1024)
    {
        printf("WritecfgItem() err. file to big(8 * 1024). not support \n");
        rv = -3;
        goto End;
    }

    while (!feof(fp))
    {
        memset(lineBuff, 0, sizeof(lineBuff));
        pTmp = fgets(lineBuff, LINEMAXLEN, fp);
        if (pTmp == NULL)
        {
            break;
        }
        pTmp = strstr(lineBuff, keyName);
        if (pTmp == NULL)
        {
            strcat(fileBuff, lineBuff);
            continue;
        }
        else
        {
            sprintf(lineBuff, "%s = %s\n", keyName, value);
            strcat(fileBuff, lineBuff);
            isContain = 1;
        }
    }

    if (isContain == 0)
    {
        sprintf(lineBuff, "%s = %s\n", keyName, value);
        strcat(fileBuff, lineBuff);
    }
    if (fp != NULL)
    {
        fclose(fp);
        fp == NULL;
    }
    fp = fopen(fileName, "wt+");
    if (fp == NULL)
    {
        printf("WritecfgItem() err.fopen() err. \n");
        rv = -3;
        goto End;
    }
    fputs(fileBuff, fp);

End:
    if (fp != NULL)
    {
        fclose(fp);
    }
    return rv;
}

