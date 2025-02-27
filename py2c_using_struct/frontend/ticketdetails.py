from PyQt6 import QtCore, QtGui, QtWidgets
import socket
import struct
fmt = '3s 4s 10s I f s'
class Ui_TicketDetails(object):
    def setupUi(self, TicketDetails):
        TicketDetails.setObjectName("TicketDetails")
        TicketDetails.resize(708, 496)
        self.verticalLayout = QtWidgets.QVBoxLayout(TicketDetails)
        self.verticalLayout.setObjectName("verticalLayout")
        self.gridLayout = QtWidgets.QGridLayout()
        self.gridLayout.setObjectName("gridLayout")
        self.label = QtWidgets.QLabel(TicketDetails)
        self.label.setObjectName("label")
        self.label.setText("Ticket Number")
        self.gridLayout.addWidget(self.label, 0, 0, 1, 1)
        self.lineEdit = QtWidgets.QLineEdit(TicketDetails)
        self.lineEdit.setObjectName("lineEdit")
        self.gridLayout.addWidget(self.lineEdit, 0, 1, 1, 3)
        self.label_2 = QtWidgets.QLabel(TicketDetails)
        self.label_2.setObjectName("label_2")
        self.label_2.setText("Venue Id")
        self.gridLayout.addWidget(self.label_2, 1, 0, 1, 1)
        self.lineEdit_2 = QtWidgets.QLineEdit(TicketDetails)
        self.lineEdit_2.setObjectName("lineEdit_2")
        self.gridLayout.addWidget(self.lineEdit_2, 1, 1, 1, 1)
        self.label_3 = QtWidgets.QLabel(TicketDetails)
        self.label_3.setObjectName("label_3")
        self.label_3.setText("Race No.")
        self.gridLayout.addWidget(self.label_3, 2, 0, 1, 1)
        self.lineEdit_3 = QtWidgets.QLineEdit(TicketDetails)
        self.lineEdit_3.setObjectName("lineEdit_3")
        self.gridLayout.addWidget(self.lineEdit_3, 2, 1, 1, 1)
        self.label_4 = QtWidgets.QLabel(TicketDetails)
        self.label_4.setObjectName("label_4")
        self.label_4.setText("Race Date")
        self.gridLayout.addWidget(self.label_4, 1, 2, 1, 1)
        self.lineEdit_4 = QtWidgets.QLineEdit(TicketDetails)
        self.lineEdit_4.setObjectName("lineEdit_4")
        self.gridLayout.addWidget(self.lineEdit_4, 1, 3, 1, 1)
        self.label_5 = QtWidgets.QLabel(TicketDetails)
        self.label_5.setObjectName("label_5")
        self.label_5.setText("BT Id")
        self.gridLayout.addWidget(self.label_5, 2, 2, 1, 1)
        self.lineEdit_5 = QtWidgets.QLineEdit(TicketDetails)
        self.lineEdit_5.setObjectName("lineEdit_5")
        self.gridLayout.addWidget(self.lineEdit_5, 2, 3, 1, 1)
        self.verticalLayout.addLayout(self.gridLayout)
        self.scrollArea = QtWidgets.QScrollArea(TicketDetails)
        self.scrollArea.setWidgetResizable(True)
        self.scrollAreaWidgetContents = QtWidgets.QWidget()
        self.scrollAreaWidgetContents.setGeometry(QtCore.QRect(0, 0, 688, 333))
        self.scrollArea.setWidget(self.scrollAreaWidgetContents)
        self.verticalLayout.addWidget(self.scrollArea)
        self.tableWidget = QtWidgets.QTableWidget(self.scrollAreaWidgetContents)
        self.tableWidget.setGeometry(QtCore.QRect(0, 0, 688, 333))
        self.tableWidget.setColumnCount(6)
        self.tableWidget.setHorizontalHeaderLabels(["Race Number", "Pool ID", "Horse Sequence", "Units", "Value", "Ticket Status"])
        self.horizontalLayout = QtWidgets.QHBoxLayout()
        self.queryButton = QtWidgets.QPushButton(TicketDetails)
        self.queryButton.setText("Query")
        self.queryButton.setMinimumSize(QtCore.QSize(150, 40))
        self.queryButton.setStyleSheet("background-color: green;")
        self.horizontalLayout.addWidget(self.queryButton)
        self.resetButton = QtWidgets.QPushButton(TicketDetails)
        self.resetButton.setText("Reset")
        self.resetButton.setMinimumSize(QtCore.QSize(150, 40))
        self.resetButton.setStyleSheet("background-color: grey;")
        self.horizontalLayout.addWidget(self.resetButton)
        self.cancelButton = QtWidgets.QPushButton(TicketDetails)
        self.cancelButton.setText("Cancel")
        self.cancelButton.setMinimumSize(QtCore.QSize(150, 40))
        self.cancelButton.setStyleSheet("background-color: red;")
        self.horizontalLayout.addWidget(self.cancelButton)
        self.verticalLayout.addLayout(self.horizontalLayout)
        self.queryButton.clicked.connect(self.fetch_data)
    def fetch_data(self):
        client_socket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
        client_socket.connect(('localhost', 8080))
        data_size = struct.calcsize(fmt)
        packed_data = client_socket.recv(data_size)
        unpacked_data = struct.unpack(fmt, packed_data)
        cRaceNum = unpacked_data[0].decode('utf-8').strip('\x00')
        cPoolId = unpacked_data[1].decode('utf-8').strip('\x00')
        cHorseSeq = unpacked_data[2].decode('utf-8').strip('\x00')
        nUnits = socket.ntohl(unpacked_data[3])
        fVal = unpacked_data[4]
        cTktSts = unpacked_data[5].decode('utf-8').strip('\x00')
        row_position = self.tableWidget.rowCount()
        self.tableWidget.insertRow(row_position)
        self.tableWidget.setItem(row_position, 0, QtWidgets.QTableWidgetItem(cRaceNum))
        self.tableWidget.setItem(row_position, 1, QtWidgets.QTableWidgetItem(cPoolId))
        self.tableWidget.setItem(row_position, 2, QtWidgets.QTableWidgetItem(cHorseSeq))
        self.tableWidget.setItem(row_position, 3, QtWidgets.QTableWidgetItem(str(nUnits)))
        self.tableWidget.setItem(row_position, 4, QtWidgets.QTableWidgetItem(f"{fVal:.2f}"))
        self.tableWidget.setItem(row_position, 5, QtWidgets.QTableWidgetItem(cTktSts))
        client_socket.close()
if __name__ == "__main__":
    import sys
    app = QtWidgets.QApplication(sys.argv)
    TicketDetails = QtWidgets.QDialog()
    ui = Ui_TicketDetails()
    ui.setupUi(TicketDetails)
    TicketDetails.show()
    sys.exit(app.exec())
