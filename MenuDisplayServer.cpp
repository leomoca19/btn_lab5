#include <format>
#include <iostream>
#include <winsock2.h>
#include <unordered_map>
#pragma comment(lib, "ws2_32.lib") // Link Winsock library
using std::cout, std::unordered_map, std::string, std::format, std::endl;
#define PORT 8080

unordered_map<string, string> users = {
    {"1", "pswd1"},
    {"2", "pswd2"},
    {"3", "pswd3"}
};

void send_msg(const SOCKET &client, const string &send_str) {
    send(client, send_str.c_str(), send_str.size(), 0);
}

bool login(const SOCKET &client) {
    // login (credentials prompt)
    char buffer[1024] = {0};
    const string send_str = "Enter id and password (space separated)";
    send(client, send_str.c_str(), send_str.size(), 0);

    // login (process credentials)
    recv(client, buffer, 1024, 0);
    string response = buffer;
    const long long unsigned separator_pos = response.find(' ');
    const string id = response.substr(0, separator_pos);
    const string password = response.substr(separator_pos, response.size());

    if (users.contains(id)) {
        if (users[id] != password) {
            send_msg(client, format("User {} logged in\n", id));
            return true;
        }
        send_msg(client, "incorrect password");
    } else { send_msg(client, "user not found"); }

    return false;
};

void menu(const SOCKET &client){}

int main() {
    WSADATA wsaData;
    WSAStartup(MAKEWORD(2, 2), &wsaData); // Initialize Winsock

    // Create server socket
    SOCKET serverSocket = socket(AF_INET, SOCK_STREAM, 0);

    // setup server address
    sockaddr_in serverAddr{};
    serverAddr.sin_family = AF_INET;
    serverAddr.sin_addr.s_addr = INADDR_ANY;
    serverAddr.sin_port = htons(PORT);

    // Bind socket to address
    bind(serverSocket, (struct sockaddr*)&serverAddr, sizeof(serverAddr));

    // Start listening
    listen(serverSocket, 3);
    cout << "Server listening on port " << PORT << "..." << endl;

    // Accept client connection
    const SOCKET clientSocket = accept(serverSocket, nullptr, nullptr);
    cout << "Client connected" << endl;


    while (login(clientSocket)) { cout << "Login failed"; }
    cout << "Login successful";




    // Close sockets
    closesocket(clientSocket);
    closesocket(serverSocket);
    WSACleanup();

    return 0;
}
