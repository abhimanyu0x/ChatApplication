#include<iostream>
#include<istream>
#include<winsock2.h>
#include<ws2tcpip.h>
#include<thread>
#include<string>
#pragma comment(lib,"ws2_32.lib")
using namespace std;
//
// intialize winsock
// create socket
// connect to the soccket
// send/recv
// close the socket
bool Initialize() {
    WSADATA data;
    return WSAStartup(MAKEWORD(2, 2), &data) == 0;
}
void sendMessage(SOCKET s) {
    cout << "Enter your chat name: " << endl;
    string name;
    getline(cin, name);
    string message;
    while (true) {
        getline(cin, message);
        string msg = name + " : " + message;
        int bytesent = send(s, msg.c_str(), msg.length(), 0);
        if (bytesent == SOCKET_ERROR) {
            cout << "Error Sending Message " << endl;
            break;
        }
        if (message == "quite") {
            cout << "Stopping the application" << endl;
            break;
        }
    }
    closesocket(s);
    WSACleanup();
}
void receiveMessage(SOCKET s) {
    char buffer[4096];
    int recvlength;
    string msg = "";
    while (true) {
        recvlength = recv(s, buffer, sizeof(buffer), 0);
        if (recvlength <= 0) {
            cout << "disconnected from the server" << endl;
            break;
        }
        else {
            msg = string(buffer, recvlength);
            cout << msg << endl;
        }
    }
    closesocket(s);
    WSACleanup();
}
int main() {
    if (!Initialize()) {
        cout << "Initialize winsock failed" << endl;
        return 1;
    }
    SOCKET s;
    s = socket(AF_INET, SOCK_STREAM, 0);
    if (s == INVALID_SOCKET) {
        cout << "invalid socket created" << endl;
        return 1;
    }
    int port = 12345;
    string serveraddress = "127.0.0.1";
    sockaddr_in serveraddr;
    serveraddr.sin_family = AF_INET;
    serveraddr.sin_port = htons(port);
    inet_pton(AF_INET, serveraddress.c_str(), &(serveraddr.sin_addr));
    if (connect(s, reinterpret_cast<sockaddr*>(&serveraddr), sizeof(serveraddr)) == SOCKET_ERROR) {
        cout << "not able to connect to server" << endl;
        closesocket(s);
        WSACleanup();
        return 1;
    }
    cout << "successfully connected to server" << endl;

    thread senderthread(sendMessage, s);
    thread receiverthread(receiveMessage, s);
    senderthread.join();
    receiverthread.join();
    return 0;
}