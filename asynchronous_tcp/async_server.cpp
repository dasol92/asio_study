#include <algorithm>
#include <boost/asio.hpp>
#include <boost/bind.hpp>
#include <iostream>
#include <list>
#include <string>

class Session {
  public:
    Session(boost::asio::io_service &io_service) : m_Socket(io_service) {
        SetConsoleOutputCP(CP_UTF8);
    }

    boost::asio::ip::tcp::socket &Socket() { return m_Socket; }

    void PostReceive() {
        memset(&m_ReceiveBuffer, '\0', sizeof(m_ReceiveBuffer));

        m_Socket.async_read_some(
            boost::asio::buffer(m_ReceiveBuffer),
            boost::bind(&Session::handle_receive, this,
                        boost::asio::placeholders::error,
                        boost::asio::placeholders::bytes_transferred)

        );
    }

  private:
    void handle_write(const boost::system::error_code & /*error*/,
                      size_t /*bytes_transferred*/) {}

    void handle_receive(const boost::system::error_code &error,
                        size_t bytes_transferred) {
        if (error) {
            if (error == boost::asio::error::eof) {
                std::cout << "Disconnected with client" << std::endl;
            } else {
                std::cout << "error No: " << error.value()
                          << " error Message: " << error.message() << std::endl;
            }
        } else {
            const std::string strRecvMessage = m_ReceiveBuffer.data();
            std::cout << "Recv: " << strRecvMessage
                      << ", bytes: " << bytes_transferred << std::endl;

            char szMessage[128] = {
                0,
            };
            sprintf_s(szMessage, 128 - 1, "Re:%s", strRecvMessage.c_str());
            m_WriteMessage = szMessage;

            boost::asio::async_write(
                m_Socket, boost::asio::buffer(m_WriteMessage),
                boost::bind(&Session::handle_write, this,
                            boost::asio::placeholders::error,
                            boost::asio::placeholders::bytes_transferred));

            PostReceive();
        }
    }

    boost::asio::ip::tcp::socket m_Socket;
    std::string m_WriteMessage;
    std::array<char, 128> m_ReceiveBuffer;
};

const unsigned short PORT_NUMBER = 31400;

class TCP_Server {
  public:
    TCP_Server(boost::asio::io_service &io_service)
        : m_acceptor(io_service, boost::asio::ip::tcp::endpoint(
                                     boost::asio::ip::tcp::v4(), PORT_NUMBER)) {
        m_pSession = nullptr;
        StartAccept();
    }

    ~TCP_Server() {
        if (m_pSession != nullptr) {
            delete m_pSession;
        }
    }

  private:
    void StartAccept() {
        std::cout << "Waiting for accept client..." << std::endl;

        m_pSession = new Session(m_acceptor.get_io_service());

        m_acceptor.async_accept(m_pSession->Socket(),
                                boost::bind(&TCP_Server::handle_accept, this,
                                            m_pSession,
                                            boost::asio::placeholders::error));
    }

    void handle_accept(Session *pSession,
                       const boost::system::error_code &error) {
        if (!error) {
            std::cout << "Accept done" << std::endl;

            pSession->PostReceive();
        }
    }

    int m_nSeqNumber;
    boost::asio::ip::tcp::acceptor m_acceptor;
    Session *m_pSession;
};

int main() {
    boost::asio::io_service io_service;

    TCP_Server server(io_service);

    io_service.run();

    std::cout << "Terminated the connection" << std::endl;

    return 0;
}