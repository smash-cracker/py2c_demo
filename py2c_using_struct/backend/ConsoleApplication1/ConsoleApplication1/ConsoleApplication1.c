#include <stdio.h>
#include <string.h>
#include <winsock2.h>
#include <ws2tcpip.h>

#define ARRAY_SIZE 3          // Maximum number of strings that can be handled
#define MAX_STRING_LEN 20     // Maximum length of each string

#pragma comment(lib, "ws2_32.lib")

typedef struct {
    char stringArray[ARRAY_SIZE][MAX_STRING_LEN];
    char singleString[MAX_STRING_LEN];
    int number;
} Data;

void decodeData(Data* data, unsigned char* buffer) {
    unsigned char* ptr = buffer;
    for (int i = 0; i < ARRAY_SIZE; i++) {
        memcpy(data->stringArray[i], ptr, MAX_STRING_LEN);
        ptr += MAX_STRING_LEN;
    }
    memcpy(data->singleString, ptr, MAX_STRING_LEN);
    ptr += MAX_STRING_LEN;
    memcpy(&data->number, ptr, sizeof(int));
}

void displayData(Data* data, int received_count) {
    printf("Array of Strings:\n");
    for (int i = 0; i < received_count; i++) {
        printf("  String %d: \"%s\"\n", i + 1, data->stringArray[i]);
    }
    printf("Single String: \"%s\"\n", data->singleString);
    printf("Integer: %d\n", data->number);
}

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
        printf("Socket creation failed\n");
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

    printf("Waiting for client connection...\n");

    client_fd = accept(server_fd, (struct sockaddr*)&client_addr, &addr_len);
    if (client_fd == INVALID_SOCKET) {
        printf("Accept failed\n");
        closesocket(server_fd);
        WSACleanup();
        return 1;
    }

    printf("Client connected.\n");

    while (1) {
        Data received_data;
        int bytes_received = recv(client_fd, (char*)&received_data, sizeof(Data), 0);

        if (bytes_received == SOCKET_ERROR) {
            printf("Receive failed\n");
            break;
        }
        else if (bytes_received == 0) {
            printf("Client disconnected\n");
            break;
        }

        int received_count = bytes_received / MAX_STRING_LEN;
        printf("Received new data:\n");
        displayData(&received_data, received_count);

        const char* ack_msg = "Data received successfully";
        send(client_fd, ack_msg, strlen(ack_msg), 0);

        // Exit the loop after a single successful receive to prevent multiple reads.
        break;
    }

    closesocket(client_fd);
    closesocket(server_fd);
    WSACleanup();

    return 0;
}
