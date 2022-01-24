#ifndef MotionLink_H
#define MotionLink_H

#include "Poco/Net/SocketAddress.h"
#include "Poco/Net/StreamSocket.h"
#include "Poco/Net/SocketStream.h"

#include <iostream>
#include <string>

namespace SemiTS {
class MotionLink {
private:
	std::string host;
	int port;
    bool bConnected;

	Poco::Net::SocketAddress socketAddr;
	Poco::Net::StreamSocket socket;
	Poco::Net::SocketStream stream;

public:
	MotionLink(std::string h, int port);
    ~MotionLink();

	bool initailize();
    bool isConnected();
};
}
#endif //MotionLink