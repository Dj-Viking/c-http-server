#include <stdio.h>
#include <assert.h>
#if _WIN32
#include <WinSock2.h>
#else
#include <sys/socket.h>
#endif
#include <ws2tcpip.h>
#include <tchar.h>

#define MY_BUFFER 1024

int start_server(void)
{
    WSADATA wsa;
    struct sockaddr_in server;
    SOCKET sockfd;
    SOCKET clientsock;
    int int_result;
    const char message[MY_BUFFER] = "something";
    char clientReq[MY_BUFFER] = {0};
    printf("------------------\n");
    printf("server starting...\n");

    int wsaStartupthing = WSAStartup(MAKEWORD(2, 2), &wsa);
    printf("wsa startup result => %d\n", wsaStartupthing);
    if (wsaStartupthing != 0)
    {
        printf("winsock startup failed\n");
        return 1;
    }

    sockfd = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
    printf("socket thingy %lld\n", sockfd);
    if (sockfd == -1)
    {
        assert(0 && "sockfd can't be -1");
        return 1;
    }

    printf("socket created successfully - sockfd thingy => %lld\n", sockfd);

    server.sin_family = AF_INET;
    server.sin_port = htons(9999);
    // NOTE: _T("") is probably the same as L"" which is CString I think
    InetPton(AF_INET, _T("127.0.0.1"), &server.sin_addr);

    int bindResult = bind(sockfd, (struct sockaddr *)&server, sizeof(server));
    if (bindResult == SOCKET_ERROR)
    {
        printf("BIND ERROR => %:d\n", WSAGetLastError());
        exit(1);
    }

    printf("listening on 127.0.0.1:9999\n");

    int listenResult = listen(sockfd, AF_INET); // LISTEN FOR CONNECTIONS

    // a way to halt the program and wait for a character to be input here
    printf("\nprogram will halt here when listening for connections to accept\n");

    clientsock = accept(sockfd, 0, 0);
    if (clientsock == SOCKET_ERROR)
    {
        printf("accept failed! => %d\n", WSAGetLastError());
        return 1;
    }
    else
    {
        printf("------------~~~---------\n");
        printf("Client connected!!! sending a message to client and close connection\n");
        send(clientsock, message, strlen(message), 0);
    }

    // just in case if client sends something we receieve it
    recv(clientsock, clientReq, sizeof(clientReq), 0);

    printf("client reply\n\n--------\n");
    printf(clientReq);
    printf("\n");

    // TODO: parse the reply and send something back like some webpage or whatever

    printf("server has started\nLOL just a test to compile and link everything in windows with cl.exe WOOHOOO\n");
    int closeResult = closesocket(sockfd);
    if (closeResult == SOCKET_ERROR)
    {
        printf("closesocket failed with error => %d\n", WSAGetLastError());
        WSACleanup();
        return 1;
    }
    WSACleanup();

    return 0;
}