/*
 * server.h
 *
 *  Created on: 23 paź 2013
 *      Author: root
 */

#ifndef SERVER_H_
#define SERVER_H_

#include <boost/asio.hpp>
#include <string>
#include <boost/noncopyable.hpp>
#include "connection.h"
#include "connection_manager.h"
//#include "request_handler.hpp"

namespace ftpsrv {

class server
  : private boost::noncopyable
{
public:

	static int portno;
  /// Construct the server to listen on the specified TCP address and port, and
  /// serve up files from the given directory.
  explicit server(const std::string& address, const std::string& port,
      const std::string& doc_root);

  /// Run the server's io_service loop.
  void run();

private:
  /// Initiate an asynchronous accept operation.
  void start_accept();

  /// Handle completion of an asynchronous accept operation.
  void handle_accept(const boost::system::error_code& e);

  /// Handle a request to stop the server.
  void handle_stop();

  /// The io_service used to perform asynchronous operations.
  boost::asio::io_service io_service_;

  /// The signal_set is used to register for process termination notifications.
  boost::asio::signal_set signals_;

  /// Acceptor used to listen for incoming connections.
  boost::asio::ip::tcp::acceptor acceptor_;

  /// The connection manager which owns all live connections.
  connection_manager connection_manager_;

  /// The next connection to be accepted.
  connection_ptr new_connection_;

  /// The handler for all incoming requests.
  //request_handler request_handler_;
};

} /* namespace ftpsrv */

#endif /* SERVER_H_ */
