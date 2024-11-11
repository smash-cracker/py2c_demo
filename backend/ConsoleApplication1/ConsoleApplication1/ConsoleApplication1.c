#include <stdio.h>
#include <string.h>
#include <winsock2.h>
#include <ws2tcpip.h>
#pragma comment(lib, "ws2_32.lib")
typedef struct {
    unsigned char head;
    unsigned char sector;
    unsigned char cyl;
} Position;
int main() {
    WSADATA wsaData;
    int server_fd, client_fd;
    struct sockaddr_in server_addr, client_addr;
    socklen_t addr_len = sizeof(client_addr);
    if (WSAStartup(MAKEWORD(2, 2), &wsaData) != 0) {
        printf("WSAStartup failed\n");
        return 1;
    }
    server_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (server_fd == INVALID_SOCKET) {
        printf("Socket failed\n");
        WSACleanup();
        return 1;
    }
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(8080);
    if (bind(server_fd, (struct sockaddr*)&server_addr, sizeof(server_addr)) == SOCKET_ERROR) {
        printf("Bind failed\n");
        closesocket(server_fd);
        WSACleanup();
        return 1;
    }
    if (listen(server_fd, 1) == SOCKET_ERROR) {
        printf("Listen failed\n");
        closesocket(server_fd);
        WSACleanup();
        return 1;
    }
    client_fd = accept(server_fd, (struct sockaddr*)&client_addr, &addr_len);
    if (client_fd == INVALID_SOCKET) {
        printf("Accept failed\n");
        closesocket(server_fd);
        WSACleanup();
        return 1;
    }
    Position pos;
    int bytes_received = recv(client_fd, (char*)&pos, sizeof(Position), 0);
    if (bytes_received == SOCKET_ERROR) {
        printf("Receive failed\n");
        closesocket(client_fd);
        closesocket(server_fd);
        WSACleanup();
        return 1;
    }
    printf("Head: %d, Sector: %d, Cyl: %d\n", pos.head, pos.sector, pos.cyl);
    closesocket(client_fd);
    closesocket(server_fd);
    WSACleanup();
    return 0;
}
