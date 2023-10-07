#pragma once

#include <vector>

#include <boost/asio.hpp>

#include "session.h"

/**
 * Listens to a socket and dispatches sessions for each incoming request.
 */
class server {

  using acceptor_t = boost::asio::ip::tcp::acceptor;
  using endpoint_t = boost::asio::ip::tcp::endpoint;
  using socket_t = boost::asio::ip::tcp::socket;

public:
  server(boost::asio::io_service &service, const std::vector<uint16_t> &ports);

  /**
   * Start listening for incoming requests.
   */
  void start_accept(size_t index);

  /**
   * Callback for when a request comes in.
   */
  void handle_accept(size_t index, std::shared_ptr<session> new_session,
                     const boost::system::error_code &ec);

private:

  /**
   * Reference to the I/O service that will call our callbacks.
   */
  boost::asio::io_service &service_;

  /**
   * List of acceptors each listening to (a different) socket.
   */
  std::vector<acceptor_t> acceptors_;
};