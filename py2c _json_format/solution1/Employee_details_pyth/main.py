import json
import os

def get_employee_details():
    employee = {
        "id": 123,
        "name": "John Doe",
        "salaries": [50000.0, 52000.0, 54000.0],
        "rating": 4.5,
    
             }
    path= os.path.join(os.path.dirname(__file__),"employee_data.json")
    with open("employee_data.json", "w") as file:
        json.dump(employee, file)
    print(f"Employee data saved at: {path}")

if __name__ == "__main__":
    get_employee_details()
