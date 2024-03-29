/**
 * @file Sender.hpp
 */

#ifndef RUBBERDAQ_INCLUDE_SENDER_HPP_
#define RUBBERDAQ_INCLUDE_SENDER_HPP_

#include "rubberdaq/ConnectionID.hpp"

#include <any>
#include <atomic>
#include <mutex>
#include <thread>
#include <iostream>

namespace dunedaq {
namespace rubberdaq {

// Typeless
class Sender {
public:
  virtual ~Sender() = default;
};

// Interface
template<typename Datatype>
class SenderConcept : public Sender {
public:
  virtual void send(Datatype& /*data*/) = 0; 
};

// QImpl
template<typename Datatype>
class QueueSenderModel : public SenderConcept<Datatype> {
public:
  explicit QueueSenderModel(ConnectionID conn_id)
    : m_conn_id(conn_id)
  {
    std::cout << "QueueSenderModel created with DT! Addr: " << this << '\n';
    // get queue ref from queueregistry based on conn_id
  }

  void send(Datatype& data) override {
    std::cout << "Handle data: " << data << '\n';
    //if (m_queue->write(
  }

  ConnectionID m_conn_id;
};

// NImpl
template<typename Datatype>
class NetworkSenderModel : public SenderConcept<Datatype> {
public:
  using SenderConcept<Datatype>::send;

  explicit NetworkSenderModel(ConnectionID conn_id)
    : SenderConcept<Datatype>(conn_id)
    , m_conn_id(conn_id)
  {
    std::cout << "NetworkSenderModel created with DT! Addr: " << this << '\n';
    // get network resources
  }

  void send(Datatype& data) override {
    std::cout << "Handle data: " << data << '\n';
    //if (m_queue->write(
  }

  ConnectionID m_conn_id;
};

} // namespace rubberdaq
} // namespace dunedaq

#endif
