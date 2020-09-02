#include "session.h"

#include <functional>
#include <iostream>
#include <thread>

using boost::asio::error::connection_reset;
using boost::asio::error::eof;
using boost::system::error_code;
using boost::system::system_error;

using std::placeholders::_1;
using std::placeholders::_2;

session::session(boost::asio::io_service &service) : socket_{service} {}

void session::start()
{
  auto handler = std::bind(&session::handle_read, shared_from_this(), _1, _2);
  socket_.async_read_some(boost::asio::buffer(buffer_), handler);
}

void session::handle_read(const error_code &ec, size_t bytes_transferred)
{
  if (ec)
  {
    if (ec == eof || ec == connection_reset)
    {
      return;
    }

    throw system_error{ec};
  }

  std::cout << "Thread " << std::this_thread::get_id() << ": Received "
            << bytes_transferred << " bytes on " << socket_.local_endpoint()
            << " from " << socket_.remote_endpoint() << std::endl;

  auto isValid = Checker().IsValid(buffer_.data(), bytes_transferred);
  if (isValid)
  {
    std::string str;
    for (auto i : buffer_)
    {
      if (i == ' ')
        continue;
      else
        str.push_back(i);
    }
    auto expression_result = Evaluate(str.c_str());
    if (expression_result.has_value())
    {
      if (expression_result.value() == "")
        return;
      std::cout << "Expression : " << buffer_.data() << "Result = " << expression_result.value() << std::endl;
      auto handler = std::bind(&session::handle_write, shared_from_this(), _1);
      boost::asio::async_write(socket_, boost::asio::buffer(expression_result.value().c_str(), expression_result.value().size()), handler);
    }
    else
    {
      std::cout << "No result then return the origin message to client\n";
      auto handler = std::bind(&session::handle_write, shared_from_this(), _1);
      boost::asio::async_write(socket_, boost::asio::buffer(buffer_.data(), bytes_transferred), handler);
    }
  }
  return;
}

void session::handle_write(const error_code &ec)
{
  if (ec)
  {
    throw system_error{ec};
  }

  auto handler = std::bind(&session::handle_read, shared_from_this(), _1, _2);
  socket_.async_read_some(boost::asio::buffer(buffer_), handler);
}