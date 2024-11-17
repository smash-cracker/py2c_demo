import socket
import struct
ARRAY_SIZE = 3
MAX_STRING_LEN = 20
fmt = f'{MAX_STRING_LEN}s' * ARRAY_SIZE + f'{MAX_STRING_LEN}s' + 'I'
def main():
    client_socket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
    client_socket.connect(('localhost', 8080))
    data_size = struct.calcsize(fmt)
    packed_data = client_socket.recv(data_size)
    unpacked_data = struct.unpack(fmt, packed_data)
    string_array = [unpacked_data[i].decode('utf-8').strip('\x00') for i in range(ARRAY_SIZE)]
    single_string = unpacked_data[ARRAY_SIZE].decode('utf-8').strip('\x00')
    number = unpacked_data[ARRAY_SIZE + 1]
    print("Received Data:")
    print("String Array:", string_array)
    print("Single String:", single_string)
    print("Integer:", number)
    client_socket.close()
if __name__ == '__main__':
    main()
