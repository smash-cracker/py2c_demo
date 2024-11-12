import json

# Sample data to write
employee_data = {
    "employee_id": 123,
    "employee_salary": 50000.50,
    "salaries": [45000.0, 48000.5, 50000.5],
    "employee_name": "John Doe"
}

# Write data to JSON file
with open("employee_data.json", "w") as json_file:
    json.dump(employee_data, json_file)
