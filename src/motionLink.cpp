#include "motionLink.h"
namespace SemiTS {
MotionLink::MotionLink(std::string h, int p) : 
	host(h), port(p), socketAddr(h, p), socket(), stream(socket), bConnected(false) {
}

MotionLink::~MotionLink() {
    if(bConnected) {
        socket.close();
    }
}

bool MotionLink::initailize() {
	try { 
		socket.connect(socketAddr); 
        bConnected = true;
	} 
	catch(Poco::Exception err) {
		std::cout << std::endl;
		return false;
	}
	return true;
}

bool MotionLink::isConnected() {
    return bConnected;
}
}//namespace SemiTS