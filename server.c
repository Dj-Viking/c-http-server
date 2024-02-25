#include <stdio.h>
#if _WIN32
#include <winsock.h>
#else
#include <sys/socket.h>
#endif
void start_server(void)
{
    printf("------------------\n");
    printf("server starting...\n");
    printf("server has started\nLOL just a test to compile and link everything in windows with cl.exe WOOHOOO\n");
}