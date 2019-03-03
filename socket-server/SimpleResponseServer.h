/*
 * SimpleResponseServer.h
 *
 *  Created on: Mar 3, 2019
 *      Author: mtwar
 */

#ifndef SIMPLERESPONSESERVER_H_
#define SIMPLERESPONSESERVER_H_

#include "Server.h"

class SimpleResponseServer: public Server {
public:
	SimpleResponseServer(const short port);
	virtual ~SimpleResponseServer();

private:
	void handleRecvBufAndPrepareSendBuf();
	void displayIncomingMessage();
	void putDateTimeIntoSendBuf(char* dateTime);
	void getDateTime(char* buf);
};

#endif /* SIMPLERESPONSESERVER_H_ */
