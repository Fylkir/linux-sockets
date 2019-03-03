/*
 * Server.cpp
 *
 *  Created on: Mar 3, 2019
 *      Author: mtwar
 */
#include "Server.h"

using namespace std;

const char* Server::LOCALHOST_IP = "0.0.0.0";


Server::Server(const short port) {
	mSockAddr.sin_family = AF_INET;
    mSockAddr.sin_port = htons(port);
    mSockLen = sizeof(mSockAddr);
    inet_pton(mSockAddr.sin_family, LOCALHOST_IP, &mSockAddr.sin_addr);
    mSockId = socket(mSockAddr.sin_family, SOCK_STREAM, 0);
    if (mSockId == -1) {
    	perror("Socket error");
    	exit(1);
    }
    if (bind(mSockId, (sockaddr*)&mSockAddr, sizeof(mSockAddr)) == -1) {
    	perror("Bind error");
    	exit(2);
    }
    if (listen(mSockId, MAX_CONNECTIONS) == -1) {
    	perror("Listen error");
    	exit(3);
    }

}

Server::~Server() {
    shutdown(mSockId, SHUT_RDWR);
}

void Server::start() {
    while(1) {
    	cout << "Waiting for connections" << endl;
    	sockaddr_in client = {};
    	const int clientSocket = accept(mSockId, (sockaddr*)&client, &mSockLen);
    	if (clientSocket < 0) {
    		perror("Accept error");
    		continue;
    	}
        if(recv(clientSocket, mRecvBuf, sizeof(mRecvBuf), 0) <= 0) {
            perror("Recv error");
            exit(5);
        }
        handleRecvBufAndPrepareSendBuf();
        if(send(clientSocket, mSendBuf, strlen(mSendBuf), 0) <= 0) {
			perror("Send error");
			exit(6);
		}
		cleanBuffers();
		shutdown(clientSocket, SHUT_RDWR);
    }

}

void Server::cleanSendBuf() {
	memset(mSendBuf, 0, sizeof(mSendBuf));
}

void Server::cleanRecvBuf() {
	memset(mRecvBuf, 0, sizeof(mRecvBuf));
}

void Server::cleanBuffers() {
	cleanRecvBuf();
	cleanSendBuf();
}
