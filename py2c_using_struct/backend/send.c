#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#ifdef _WIN32
#include <winsock2.h>
#include <ws2tcpip.h>
#pragma comment(lib, "ws2_32.lib")
typedef int socklen_t;
#else
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/types.h>
#include <sys/socket.h>
#define INVALID_SOCKET -1
#define SOCKET_ERROR -1
typedef int SOCKET;
#define closesocket close
#endif
#define ARRAY_SIZE 3
#define MAX_STRING_LEN 20
typedef struct
{
    char stringArray[ARRAY_SIZE][MAX_STRING_LEN];
    char singleString[MAX_STRING_LEN];
    int number;
} Data;
int main()
{
#ifdef _WIN32
    WSADATA wsaData;
    if (WSAStartup(MAKEWORD(2, 2), &wsaData) != 0)
    {
        printf("WSAStartup failed\n");
        return 1;
    }
#endif
    SOCKET server_fd, client_fd;
    struct sockaddr_in server_addr, client_addr;
    socklen_t addr_len = sizeof(client_addr);
    server_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (server_fd == INVALID_SOCKET)
    {
        printf("Socket creation failed\n");
#ifdef _WIN32
        WSACleanup();
#endif
        return 1;
    }
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(8080);
    if (bind(server_fd, (struct sockaddr *)&server_addr, sizeof(server_addr)) == SOCKET_ERROR)
    {
        printf("Bind failed\n");
        closesocket(server_fd);
#ifdef _WIN32
        WSACleanup();
#endif
        return 1;
    }
    if (listen(server_fd, 1) == SOCKET_ERROR)
    {
        printf("Listen failed\n");
        closesocket(server_fd);
#ifdef _WIN32
        WSACleanup();
#endif
        return 1;
    }
    printf("Waiting for client connection...\n");
    client_fd = accept(server_fd, (struct sockaddr *)&client_addr, &addr_len);
    if (client_fd == INVALID_SOCKET)
    {
        printf("Accept failed\n");
        closesocket(server_fd);
#ifdef _WIN32
        WSACleanup();
#endif
        return 1;
    }
    printf("Client connected.\n");
    Data send_data = {
        .stringArray = {"Hello", "from", "C"},
        .singleString = "Greetings!",
        .number = htonl(1234)};
    send(client_fd, (char *)&send_data, sizeof(send_data), 0);
    printf("Data sent to client.\n");
    closesocket(client_fd);
    closesocket(server_fd);
#ifdef _WIN32
    WSACleanup();
#endif
    return 0;
}