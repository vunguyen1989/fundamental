#include "server.h"

#include <functional>

#include <boost/asio.hpp>

using std::placeholders::_1;
using std::placeholders::_2;

using boost::asio::io_service;
using boost::asio::error::eof;
using boost::system::error_code;
using boost::system::system_error;

server::server(boost::asio::io_service &service,
               const std::vector<uint16_t> &ports)
    : service_{service} {

  auto create_acceptor = [&](uint16_t port) {
    acceptor_t acceptor{service};
    endpoint_t endpoint{boost::asio::ip::tcp::v4(), port};
    acceptor.open(endpoint.protocol());
    acceptor.set_option(acceptor_t::reuse_address(false));
    acceptor.bind(endpoint);
    acceptor.listen();
    return acceptor;
  };

  std::transform(ports.begin(), ports.end(), std::back_inserter(acceptors_),
                 create_acceptor);

  for (size_t i = 0; i < acceptors_.size(); i++) {
    start_accept(i);
  }
}

void server::start_accept(size_t index) {
  auto new_session{std::make_shared<session>(service_)};

  auto handler =
      std::bind(&server::handle_accept, this, index, new_session, _1);

  acceptors_[index].async_accept(new_session->socket(), handler);
}

void server::handle_accept(size_t index, std::shared_ptr<session> new_session,
                           const boost::system::error_code &ec) {
  if (ec) {
    throw system_error{ec};
  }

  new_session->start();
  start_accept(index);
}