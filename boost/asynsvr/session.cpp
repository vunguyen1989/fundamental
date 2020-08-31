#include "session.h"

#include <functional>
#include <iostream>
#include <thread>

using boost::asio::async_write;
using boost::asio::buffer;
using boost::asio::io_service;
using boost::asio::error::connection_reset;
using boost::asio::error::eof;
using boost::system::error_code;
using boost::system::system_error;

using std::placeholders::_1;
using std::placeholders::_2;

session::session(io_service &service) : socket_{service} {}

void session::start() {
  auto handler = std::bind(&session::handle_read, shared_from_this(), _1, _2);
  socket_.async_read_some(buffer(buffer_), handler);
}

void session::handle_read(const error_code &ec, size_t bytes_transferred) {
  if (ec) {
    if (ec == eof || ec == connection_reset) {
      return;
    }

    throw system_error{ec};
  }

  std::cout << "Thread " << std::this_thread::get_id() << ": Received "
            << bytes_transferred << " bytes on " << socket_.local_endpoint()
            << " from " << socket_.remote_endpoint() << std::endl;

  auto handler = std::bind(&session::handle_write, shared_from_this(), _1);
  async_write(socket_, buffer(buffer_.data(), bytes_transferred), handler);
}

void session::handle_write(const error_code &ec) {
  if (ec) {
    throw system_error{ec};
  }

  auto handler = std::bind(&session::handle_read, shared_from_this(), _1, _2);
  socket_.async_read_some(buffer(buffer_), handler);
}