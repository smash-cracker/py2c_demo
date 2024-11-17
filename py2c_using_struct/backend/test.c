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

void displayData(Data *data)
{
    printf("Array of Strings:\n");
    for (int i = 0; i < ARRAY_SIZE; i++)
    {
        printf("  String %d: \"%s\"\n", i + 1, data->stringArray[i]);
    }
    printf("Single String: \"%s\"\n", data->singleString);
    data->number = ntohl(data->number);
    printf("Integer: %d\n", data->number);
}

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

    Data received_data;
    int bytes_received = recv(client_fd, (char *)&received_data, sizeof(Data), 0);

    if (bytes_received == SOCKET_ERROR)
    {
        printf("Receive failed\n");
    }
    else if (bytes_received == 0)
    {
        printf("Client disconnected\n");
    }
    else
    {
        printf("Received new data:\n");
        displayData(&received_data);
    }

    const char *ack_msg = "Data received successfully";
    send(client_fd, ack_msg, strlen(ack_msg), 0);

    closesocket(client_fd);
    closesocket(server_fd);

#ifdef _WIN32
    WSACleanup();
#endif

    return 0;
}
