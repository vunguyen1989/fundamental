//
// blocking_tcp_echo_client.cpp
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//
// Copyright (c) 2003-2010 Christopher M. Kohlhoff (chris at kohlhoff dot com)
//
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
//

#include <boost/asio.hpp>
#include <chrono>
#include <cstdlib>
#include <cstring>
#include <iostream>
using boost::asio::ip::tcp;

enum
{
  max_length = 1024
};

int main(int argc, char *argv[])
{
  try
  {
    boost::asio::io_service io_service;
    tcp::resolver resolver(io_service);
    tcp::resolver::query query(tcp::v4(), "127.0.0.1", "5001");
    tcp::resolver::iterator iterator = resolver.resolve(query);
    tcp::socket s(io_service);
    s.connect(*iterator);

    char *request = "(4 + 3) * 2 / 5 + ((12 + 9) / 2) * 5 + (3 / 2 + 2 * 4) * 7 + (4 - 6 / 3) + 1 - 10\n";
    size_t request_length = std::strlen(request);
    auto t1 = std::chrono::high_resolution_clock::now();
    for (auto i = 0u; i < 100000; i++) //8.2M
    {
      boost::asio::write(s, boost::asio::buffer(request, request_length));
      char reply[3];
      size_t reply_length = boost::asio::read(s,
                                              boost::asio::buffer(reply, 3));
    }
    auto t2 = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::seconds>(t2 - t1).count();
    std::cout << duration << " sec for 8.2M data" << std::endl;
  }
  catch (std::exception &e)
  {
    std::cerr << "Exception: " << e.what() << "\n";
  }

  return 0;
}