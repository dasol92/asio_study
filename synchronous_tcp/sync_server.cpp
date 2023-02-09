#include <boost/asio.hpp>
#include <iostream>

const char SERVER_IP[] = "127.0.0.1";
const unsigned short PORT_NUMBER = 31400;

int main(int, char **) {
    boost::asio::io_service io_service;
    boost::asio::ip::tcp::endpoint endpoint(boost::asio::ip::tcp::v4(),
                                            PORT_NUMBER);
    boost::asio::ip::tcp::acceptor acceptor(io_service, endpoint);

    boost::asio::ip::tcp::socket socket(io_service);
    acceptor.accept(socket);
    std::cout << "Accept client" << std::endl;

    while (true) {
        std::array<char, 128> buf;
        buf.fill(0);
        boost::system::error_code error;
        size_t len = socket.read_some(boost::asio::buffer(buf), error);
        if (error) {
            if (error == boost::asio::error::eof) {
                std::cout << "Disconnected with client" << std::endl;
            } else {
                std::cout << "Error No: " << error.value()
                          << " error Message: " << error.message() << std::endl;
            }
            break;
        }
        std::cout << "Received: " << &buf[0] << std::endl;
        char szMessage[128] = {
            0,
        };
        sprintf_s(szMessage, 128 - 1, "Re:%s", &buf[0]);
        size_t nMsgLen = strnlen_s(szMessage, 128 - 1);
        boost::system::error_code ignored_error;
        socket.write_some(boost::asio::buffer(szMessage, nMsgLen),
                          ignored_error);
        std::cout << "Sent: " << szMessage << std::endl;
    }
    return 0;
}
