#ifndef _SOCKETCLIENT_H_
#define _SOCKETCLIENT_H_

#ifdef __cplusplus
extern "C" {
#endif

//初始化
int socketClientInit(void **handle);
//发送
int socketClientSend(void *handle, unsigned char *pBuf, int buflen);
//接收
int socketClientRecive(void *handle, unsigned char *pBuf, int *buflen);
//释放
int socketClientFree(void **handle);

#ifdef __cplusplus
}
#endif

#endif