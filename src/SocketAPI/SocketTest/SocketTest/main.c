#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "SocketClient.h"
int main(void)
{
	int tmp = 0, ret = 0;
	void *handle = NULL;
	unsigned char send[128];
	unsigned char recive[128];
	int recivelen = 0;
	strcpy(send, "asdfwefwfsdvdfwef");
	tmp = socketClientInit(&handle);
	if (tmp != 0)
	{
		ret = -1;
		printf("err1\n");
		return ret;
	}

	tmp = socketClientSend(handle, send, strlen(send));
	if (tmp != 0)
	{
		ret = -2;
		printf("err2\n");
		return ret;
	}
	tmp = socketClientRecive(handle, recive, &recivelen);
	if (tmp != 0)
	{
		ret = -3;
		printf("err3\n");
		return ret;
	}
	recive[recivelen] = '\0';
	printf("%s\n", recive);
	tmp = socketClientFree(&handle);
	if (tmp != 0)
	{
		ret = -4;
		printf("err4\n");
		return ret;
	}
	return 0;
}