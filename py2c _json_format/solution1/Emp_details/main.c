#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <winsock2.h>
#include "cJSON.h"

#pragma comment(lib, "ws2_32.lib")  // Link Winsock library

#define PORT 8080
#define BUFFER_SIZE 1024

int main() {
    WSADATA wsa;
    SOCKET server_socket, client_socket;
    struct sockaddr_in server_addr, client_addr;
    int client_addr_size, recv_size;
    char buffer[BUFFER_SIZE];

    // Initialize Winsock
    if (WSAStartup(MAKEWORD(2, 2), &wsa) != 0) {
        printf("Failed to initialize Winsock. Error Code: %d\n", WSAGetLastError());
        return 1;
    }

    // Create socket
    server_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (server_socket == INVALID_SOCKET) {
        printf("Could not create socket. Error Code: %d\n", WSAGetLastError());
        WSACleanup();
        return 1;
    }

    // Prepare the sockaddr_in structure
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(PORT);

    // Bind
    if (bind(server_socket, (struct sockaddr*)&server_addr, sizeof(server_addr)) == SOCKET_ERROR) {
        printf("Bind failed. Error Code: %d\n", WSAGetLastError());
        closesocket(server_socket);
        WSACleanup();
        return 1;
    }

    // Listen
    listen(server_socket, 3);

    printf("Waiting for incoming connections...\n");
    client_addr_size = sizeof(struct sockaddr_in);

    // Accept a connection from the client
    client_socket = accept(server_socket, (struct sockaddr*)&client_addr, &client_addr_size);
    if (client_socket == INVALID_SOCKET) {
        printf("Accept failed. Error Code: %d\n", WSAGetLastError());
        closesocket(server_socket);
        WSACleanup();
        return 1;
    }

    printf("Connection accepted.\n");

    // Receive data from the client
    if ((recv_size = recv(client_socket, buffer, BUFFER_SIZE, 0)) == SOCKET_ERROR) {
        printf("Recv failed. Error Code: %d\n", WSAGetLastError());
        closesocket(client_socket);
        closesocket(server_socket);
        WSACleanup();
        return 1;
    }

    buffer[recv_size] = '\0'; // Null-terminate the received data
   // printf("Received JSON: %s\n", buffer);

    // Parse JSON data using cJSON
    cJSON* json = cJSON_Parse(buffer);
    if (json == NULL) {
        printf("Error parsing JSON data.\n");
        closesocket(client_socket);
        closesocket(server_socket);
        WSACleanup();
        return 1;
    }


    // Extract values from JSON
    cJSON* name = cJSON_GetObjectItem(json, "name");
    cJSON* age = cJSON_GetObjectItem(json, "age");
    cJSON* height = cJSON_GetObjectItem(json, "height");
    cJSON* scores = cJSON_GetObjectItem(json, "scores");
    cJSON* address = cJSON_GetObjectItem(json, "addrs");

    if (cJSON_IsString(name) && cJSON_IsNumber(age) && cJSON_IsString(height) && cJSON_IsArray(scores)&& cJSON_IsString(address)) {
        printf("\n\n Name: %s\n",name->valuestring);
        printf(" Age: %d\n", age->valueint);
        printf(" Height: %s\n", height->valuestring);  
       printf(" Address: %s\n", address->valuestring);

  int array_size = cJSON_GetArraySize(scores);
       printf(" Scores:");
            for (int i = 0; i < array_size; i++) {
               cJSON* item = cJSON_GetArrayItem(scores, i);
               if (cJSON_IsString(item)) {
                   printf(" %s  ", item->valuestring);
               }
           }
         printf("\n\n");
        }
    else {
        printf("JSON format is incorrect.\n");
    }

    // Clean up cJSON
    cJSON_Delete(json);

    // Close sockets and cleanup Winsock
    closesocket(client_socket);
    closesocket(server_socket);
    WSACleanup();

    return 0;
}
