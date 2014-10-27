#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "itcastlog.h"

struct _socketHandle
{
	char version[16];
	char serverIp[16];
	int serverPort;
	unsigned char *pBuf;
	int buflen;
};
typedef struct _socketHandle socketHandle;

//初始化
__declspec(dllexport)
int socketClientInit(void **handle)
{
	int ret = 0;
	socketHandle *ph = NULL;
	ph = (socketHandle *)malloc(sizeof(socketHandle));
	if (ph == NULL)
	{
		ret = -1;
		ITCAST_LOG(__FILE__, __LINE__, 4, 4, "socketClientInit() err. malloc err\n");
		return ret;
	}
	strcpy(ph->version, "1.0.0");
	strcpy(ph->serverIp, "192.168.1.12");
	ph->serverPort = 8080;
	ph->pBuf = NULL;
	ph->buflen = 0;
	*handle = ph;
	return ret;
}

//发送
__declspec(dllexport)
int socketClientSend(void *handle, unsigned char *pBuf, int buflen)
{
	int ret = 0;
	socketHandle *sh = NULL;
	if (handle == NULL || pBuf == NULL || buflen < 0)
	{
		ret = -1;
		ITCAST_LOG(__FILE__, __LINE__, 4, 4,
			"socketClientSend() err. param err\n");
		return ret;
	}
	sh = (socketHandle *)handle;
	sh->pBuf = (unsigned char *)malloc(buflen * sizeof(char));
	if (sh->pBuf == NULL)
	{
		ret = -2;
		ITCAST_LOG(__FILE__, __LINE__, 4, 4, 
			"socketClientSend() err. malloc err\n");
	}

	memcpy(sh->pBuf, pBuf, buflen);
	sh->buflen = buflen;
	return ret;
}
//接收
__declspec(dllexport)
int socketClientRecive(void *handle, unsigned char *pBuf, int *buflen)
{
	int ret = 0;
	socketHandle *sh = NULL;
	if (handle == NULL || pBuf == NULL || buflen == NULL)
	{
		ret = -1;
		ITCAST_LOG(__FILE__, __LINE__, 4, 4, 
			"socketClientRecive() err. param err.\n");
		return ret;
	}
	sh = (socketHandle *)handle;
	memcpy(pBuf, sh->pBuf, sh->buflen);
	*buflen = sh->buflen;
	return ret;
}
//释放
__declspec(dllexport)
int socketClientFree(void **handle)
{
	int ret = 0;
	socketHandle *sh = (socketHandle *)(*handle);
	if (handle == NULL)
	{
		ret = -1;
		ITCAST_LOG(__FILE__, __LINE__, 4, 4, 
			"socketClientFree() param err.\n");
		return ret;
	}
	if (sh->pBuf != NULL)
	{
		free(sh->pBuf);
	}
	free(sh);
	*handle = NULL;
	return ret;
}