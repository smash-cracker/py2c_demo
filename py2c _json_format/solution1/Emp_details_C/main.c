#ifdef _WIN32
#include <winsock2.h>
#include <ws2tcpip.h>
#pragma comment(lib, "ws2_32.lib")
#else
#include <unistd.h>
#include <arpa/inet.h>
#endif

#include <stdio.h>
#include <string.h>

#define BUFFER_SIZE 1024
#define SERVER_PORT 65433
#define SERVER_ADDR "127.0.0.1"

int main() {
    int sock;
    struct sockaddr_in server_address;
    char buffer[BUFFER_SIZE];

#ifdef _WIN32
    WSADATA wsaData;
    // Initialize Winsock
    if (WSAStartup(MAKEWORD(2, 2), &wsaData) != 0) {
        printf("WSAStartup failed\n");
        return 1;
    }
#endif

    // Create a socket
    sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) {
        perror("Socket creation failed");
        return 1;
    }

    // Set up the server address
    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(SERVER_PORT);
    inet_pton(AF_INET, SERVER_ADDR, &server_address.sin_addr);

    // Connect to the server
    if (connect(sock, (struct sockaddr*)&server_address, sizeof(server_address)) < 0) {
        perror("Connection failed");
        return 1;
    }
    printf("Connected to server.\n");

    // Receive data
    int bytes_received = recv(sock, buffer, BUFFER_SIZE, 0);
    if (bytes_received <= 0) {
        perror("Failed to receive data");
        if (sock != -1) {
#ifdef _WIN32
            closesocket(sock);
#else
            close(sock);
#endif
        }
        return 1;
    }

    // Parse data
    int employee_id;
    float employee_salary;
    int salaries_length;
    int offset = 0;

    // Extract employee_id, employee_salary, and salaries_length
    memcpy(&employee_id, buffer + offset, sizeof(int));
    offset += sizeof(int);

    memcpy(&employee_salary, buffer + offset, sizeof(float));
    offset += sizeof(float);

    memcpy(&salaries_length, buffer + offset, sizeof(int));
    offset += sizeof(int);

    // Print the basic information
    printf("Received Employee Details:\n");
    printf("ID: %d\n", employee_id);
    printf("Salary: %.2f\n", employee_salary);

    // Read and print the salary array
    printf("Salaries: ");
    float salary;
    for (int i = 0; i < salaries_length; ++i) {
        memcpy(&salary, buffer + offset, sizeof(float));
        printf("%.2f ", salary);
        offset += sizeof(float);
    }
    printf("\n");

    // Read and print the name
    char employee_name[BUFFER_SIZE];

#ifdef _WIN32
    strcpy_s(employee_name, sizeof(employee_name), buffer + offset);  // Correct use of strcpy_s
#else
    strcpy(employee_name, buffer + offset);  // For non-Windows platforms, use strcpy
#endif
    printf("Name: %s\n", employee_name);

    // Close the socket
#ifdef _WIN32
    closesocket(sock);
    WSACleanup();  // Clean up Winsock
#else
    close(sock);
#endif

    return 0;
}
