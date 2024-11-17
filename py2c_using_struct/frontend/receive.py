import socket
import struct
fmt = '3s 4s 10s I f s'
def main():
    client_socket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
    client_socket.connect(('localhost', 8080))
    data_size = struct.calcsize(fmt)
    packed_data = client_socket.recv(data_size)
    unpacked_data = struct.unpack(fmt, packed_data)
    cRaceNum = unpacked_data[0].decode('utf-8')
    cPoolId = unpacked_data[1].decode('utf-8')
    cHorseSeq = unpacked_data[2].decode('utf-8')
    nUnits = socket.ntohl(unpacked_data[3])  
    fVal = unpacked_data[4]  
    cTktSts = unpacked_data[5]  
    print("Received Data:")
    print("Race Number:", cRaceNum)
    print("Pool ID:", cPoolId)
    print("Horse Sequence:", cHorseSeq)
    print("Units:", nUnits)
    print("Value:", fVal)
    print("Ticket Status", cTktSts)
    client_socket.close()
if __name__ == '__main__':
    main()
