import sys
import socket
import cstruct
from PyQt5.QtCore import QCoreApplication, QThread, pyqtSignal
class Position(cstruct.MemCStruct):
    __byte_order__ = cstruct.LITTLE_ENDIAN
    __def__ = """
        struct {
            unsigned char head;
            unsigned char sector;
            unsigned char cyl;
        }
    """
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
class MyApp(QCoreApplication):
    def __init__(self, packed_data, host, port):
        super().__init__(sys.argv)
        self.client_thread = TcpClientThread(packed_data, host, port)
        self.client_thread.start()
if __name__ == '__main__':
    pos = Position(head=10, sector=20, cyl=3)
    packed = pos.pack()
    app = MyApp(packed, 'localhost', 8080)
    sys.exit(app.exec_())
