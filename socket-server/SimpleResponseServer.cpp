/*
 * SimpleResponseServer.cpp
 *
 *  Created on: Mar 3, 2019
 *      Author: mtwar
 */

#include "SimpleResponseServer.h"
#include <time.h>

SimpleResponseServer::SimpleResponseServer(const short port) : Server(port) {

}

SimpleResponseServer::~SimpleResponseServer() {

}

void SimpleResponseServer::handleRecvBufAndPrepareSendBuf() {
	displayIncomingMessage();
	char dateTime[100];
	getDateTime(mSendBuf);
}

void SimpleResponseServer::displayIncomingMessage() {
	std::cout << mRecvBuf << std::endl;
}

void SimpleResponseServer::getDateTime(char* buf) {
	time_t t = time(NULL);
	tm tm = *localtime(&t);
	sprintf(buf, "now: %d-%d-%d %d:%d:%d\n", tm.tm_year + 1900, tm.tm_mon + 1, tm.tm_mday, tm.tm_hour, tm.tm_min, tm.tm_sec);
}

