#include <iostream>
#include "Poco/Util/Util.h"
#include "Poco/Util/Application.h"
#include "Poco/Event.h"
#include "Poco/AutoPtr.h"
#include "Poco/DateTime.h"
#include "motionLink.h"

using namespace SemiTS;


int main(int argc, char** argv)		
{									
    try
	{     							
        Poco::AutoPtr<MotionLink> ml = new MotionLink("127.0.0.1", 6379);
        //ml->initailize();
    }								
    catch (Poco::Exception& exc)	
    {								
        std::cerr << exc.displayText() << std::endl;	
        return Poco::Util::Application::EXIT_SOFTWARE; 	
    }								
}