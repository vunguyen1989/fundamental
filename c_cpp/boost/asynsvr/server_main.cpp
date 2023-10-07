#include "server.h"

#include <numeric>

#include <boost/asio.hpp>
#include <boost/thread.hpp>

int main() {
  std::vector<uint16_t> ports{};

  // Fill ports with range [5000,5000+n)
  ports.resize(10);
  std::iota(ports.begin(), ports.end(), 5000);

  boost::asio::io_service service{};

  server s{service, ports};

  // Spawn thread group for running the I/O service
  size_t thread_count = std::min(
      static_cast<size_t>(boost::thread::hardware_concurrency()), ports.size());

  boost::thread_group tg{};
  for (size_t i = 0; i < thread_count; ++i) {
    tg.create_thread([&]() { service.run(); });
  }

  tg.join_all();

  return 0;
}