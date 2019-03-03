/*
 * Server.h
 *
 *  Created on: Mar 3, 2019
 *      Author: mtwar
 */

#ifndef SERVER_H_
#define SERVER_H_

#include <iostream>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <string.h>
#include <netdb.h>

class Server {
public:
	Server(const short port);
	virtual ~Server();
	void start();


private:
	static const unsigned short MAX_MSG_LEN = 4096;
	static const unsigned short MAX_CONNECTIONS = 10;
	static const char* LOCALHOST_IP;

	sockaddr_in mSockAddr;
	int mSockId;
	socklen_t mSockLen;

	void cleanRecvBuf();
	void cleanSendBuf();
	void cleanBuffers();

protected:
	char mSendBuf[MAX_MSG_LEN];
	char mRecvBuf[MAX_MSG_LEN];
	virtual void handleRecvBufAndPrepareSendBuf() = 0;

};

#endif /* SERVER_H_ */
