#include <iostream>
#include <string>
#include <boost/asio.hpp>
#include <boost/bind.hpp>
#include <boost/thread/thread.hpp>
#include "connection.h"
#include "server.h"

int main(int argc, char* argv[])
{


  try
  {
    // Check command line arguments.
    if (argc != 4)
    {
      std::cerr << "Usage: http_server <address> <port> <doc_root>\n";
      std::cerr << "  For IPv4, try:\n";
      std::cerr << "    receiver 0.0.0.0 80 .\n";
      std::cerr << "  For IPv6, try:\n";
      std::cerr << "    receiver 0::0 80 .\n";
      return 1;
    }

    // Initialise the server.
    ftpsrv::server s(argv[1], argv[2], argv[3]);
    //ftpsrv::server::portno = 10000;
    s.run();
    int x = 9;
    do {
    	std::cin >> x;
    	std::cout << "xxx:" << x;
    } while (x!=0);
    // Run the server until stopped.
    /*boost::thread t(boost::bind(&http::server::server::run, &s));
    boost::thread t2(boost::bind(&http::server::server::run, &s));
    boost::thread t3(boost::bind(&http::server::server::run, &s));
    int x;
    do {
    	std::cin >> x;
    	std::cout << "xxx:" << x;
    } while (x!=0);*/
    //t.join();

    //s.run();
  }
  catch (std::exception& e)
  {
    std::cerr << "exception: " << e.what() << "\n";
  }

  return 0;
}
