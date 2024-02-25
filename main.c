#include <stdio.h>
#include "./server.h"

int main(void)
{
	int result = start_server();
	if (result != 0)
	{
		printf("there was some error after server start %d", result);
		exit(result);
	}
	return result;
}
