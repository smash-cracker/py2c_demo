import sys
import socket
import struct
ARRAY_SIZE = 3            
MAX_STRING_LEN = 20   
from PyQt5.QtCore import QThread
from PyQt5.QtWidgets import QApplication, QWidget, QVBoxLayout, QLineEdit, QPushButton, QSpinBox, QLabel, QListWidget, QInputDialog
class TcpClientThread(QThread):
    def __init__(self, packed_data, host, port):
        super().__init__()
        self.packed_data = packed_data
        self.host = host
        self.port = port
    def run(self):
        client_socket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
        client_socket.connect((self.host, self.port))
        client_socket.sendall(self.packed_data)
        client_socket.close()
class MyApp:
    def __init__(self):
        self.app = QApplication(sys.argv)
        self.ui = MyWindow()
        self.ui.show()
    def start_client_thread(self, packed_data):
        self.client_thread = TcpClientThread(packed_data, 'localhost', 8080)
        self.client_thread.start()
class MyWindow(QWidget):
    def __init__(self):
        super().__init__()
        self.setWindowTitle("Data Input UI")
        self.setGeometry(100, 100, 400, 300)
        self.layout = QVBoxLayout()
        self.integer_label = QLabel("Enter an integer:")
        self.integer_input = QSpinBox()
        self.layout.addWidget(self.integer_label)
        self.layout.addWidget(self.integer_input)
        self.string_label = QLabel("Enter a string:")
        self.string_input = QLineEdit()
        self.layout.addWidget(self.string_label)
        self.layout.addWidget(self.string_input)
        self.array_label = QLabel("Enter an array of strings (one per line):")
        self.array_input = QListWidget()
        self.layout.addWidget(self.array_label)
        self.layout.addWidget(self.array_input)
        self.array_input.addItem("Item 1")
        self.array_input.addItem("Item 2")
        self.add_button = QPushButton("Add Item")
        self.add_button.clicked.connect(self.add_item)
        self.layout.addWidget(self.add_button)
        self.delete_button = QPushButton("Delete Selected Item")
        self.delete_button.clicked.connect(self.delete_item)
        self.layout.addWidget(self.delete_button)
        self.send_button = QPushButton("Send Data")
        self.send_button.clicked.connect(self.send_data)
        self.layout.addWidget(self.send_button)
        self.setLayout(self.layout)
    def add_item(self):
        text, ok = QInputDialog.getText(self, "Add Item", "Enter a string:")
        if ok and text:
            self.array_input.addItem(text)
    def delete_item(self):
        selected_item = self.array_input.currentRow()
        if selected_item != -1:
            self.array_input.takeItem(selected_item)
    def pad_string(self, s, length):
        return s.encode('utf-8').ljust(length, b'\x00')[:length]
    def send_data(self):
        integer_value = self.integer_input.value()
        string_value = self.string_input.text()
        array_of_strings = []
        array_of_strings = [self.array_input.item(i).text() for i in range(self.array_input.count())]
        while len(array_of_strings) < ARRAY_SIZE:
                array_of_strings.append("")
        array_of_strings = array_of_strings[:ARRAY_SIZE]
        data = {
            'string_array': array_of_strings,
            'single_string': string_value,
            'number': integer_value
        }
        print("Packing the following data:")
        print(f"String Array: {data['string_array']}")
        print(f"Single String: {data['single_string']}")
        print(f"Integer: {data['number']}")
        packed_data = b''
        for s in data['string_array']:
            packed_data += self.pad_string(s, MAX_STRING_LEN)
        packed_data += self.pad_string(data['single_string'], MAX_STRING_LEN)
        packed_data += struct.pack('I', data['number'])
        print("Packed Data:", packed_data)
        app.start_client_thread(packed_data)
if __name__ == '__main__':
    app = MyApp()
    sys.exit(app.app.exec_())
