#ifndef _SOCKETCLIENT_H_
#define _SOCKETCLIENT_H_

#ifdef __cplusplus
extern "C" {
#endif

//��ʼ��
int socketClientInit(void **handle);
//����
int socketClientSend(void *handle, unsigned char *pBuf, int buflen);
//����
int socketClientRecive(void *handle, unsigned char *pBuf, int *buflen);
//�ͷ�
int socketClientFree(void **handle);

#ifdef __cplusplus
}
#endif

#endif