#include <iostream>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <string.h>
#include <netdb.h>
#include "SimpleResponseServer.h"

using namespace std;
const short PORT = 50000;

int main(int argc, char **argv) {

	SimpleResponseServer server(PORT);
	server.start();
    return 0;
}

