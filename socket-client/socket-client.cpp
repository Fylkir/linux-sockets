#include <iostream>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <string.h>
#include <netdb.h>

using namespace std;
const unsigned short MAX_MSG_LEN = 4096;
const unsigned short MAX_CONNECTIONS = 10;
const short SERVER_PORT = 50000;
const char* SERVER_IP = "192.168.1.108";

int main(int argc, char **argv) {

    char buffer[MAX_MSG_LEN];
	std::string msg;
	sockaddr_in server =
    {
        .sin_family = AF_INET,
        .sin_port = htons(SERVER_PORT)
    };
    socklen_t len = sizeof(server);
    inet_pton(server.sin_family, SERVER_IP, &server.sin_addr);
    const int s = socket(server.sin_family, SOCK_STREAM, 0);
    if (s == -1) return -1;
    if (connect(s, (sockaddr*)&server, sizeof(server)) < 0) {
    	perror("connect error");
    	return -1;
    }
    cin >> msg;
    strcpy(buffer, msg.c_str());
    send(s, buffer, sizeof(buffer), 0);
    char recBuffer[MAX_MSG_LEN];
    while(recv(s, recBuffer, sizeof(buffer), 0) > 0) {
    	puts(recBuffer);
    }
    shutdown(s, SHUT_RDWR);

    return 0;
}

