#include <stdio.h>
#include <stdlib.h>
#include "cJSON.h"

int main() {
    // Open the JSON file
    FILE* file = fopen("employee_data.json", "r");
    if (file == NULL) {
        perror("Unable to open file");
        return 1;
    }

    // Read the JSON file content
    fseek(file, 0, SEEK_END);
    long file_size = ftell(file);
    fseek(file, 0, SEEK_SET);
    char* json_data = (char*)malloc(file_size + 1);
    fread(json_data, 1, file_size, file);
    fclose(file);

    // Parse the JSON data
    cJSON* json = cJSON_Parse(json_data);
    if (json == NULL) {
        printf("Error parsing JSON\n");
        free(json_data);
        return 1;
    }

    // Extract data from JSON
    int employee_id = cJSON_GetObjectItem(json, "employee_id")->valueint;
    float employee_salary = (float)cJSON_GetObjectItem(json, "employee_salary")->valuedouble;
    const char* employee_name = cJSON_GetObjectItem(json, "employee_name")->valuestring;

    cJSON* salaries = cJSON_GetObjectItem(json, "salaries");
    printf("Employee ID: %d\n", employee_id);
    printf("Employee Salary: %.2f\n", employee_salary);
    printf("Employee Name: %s\n", employee_name);
    printf("Salaries: ");
    for (int i = 0; i < cJSON_GetArraySize(salaries); i++) {
        printf("%.2f ", (float)cJSON_GetArrayItem(salaries, i)->valuedouble);
    }
    printf("\n");

    // Clean up
    cJSON_Delete(json);
    free(json_data);

    return 0;
}
