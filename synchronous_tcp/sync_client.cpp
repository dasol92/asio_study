#include <boost/asio.hpp>
#include <iostream>

const char SERVER_IP[] = "127.0.0.1";
const unsigned short PORT_NUMBER = 31400;

int main() {
    boost::asio::io_service io_service;

    boost::asio::ip::tcp::endpoint endpoint(
        boost::asio::ip::address::from_string(SERVER_IP), PORT_NUMBER);

    boost::system::error_code connect_error;
    boost::asio::ip::tcp::socket socket(io_service);

    socket.connect(endpoint, connect_error);

    if (connect_error) {
        std::cout << "Failed to connect. error No: " << connect_error.value()
                  << ", Message: " << connect_error.message() << std::endl;
        getchar();
        return 0;
    } else {
        std::cout << "Connected with server" << std::endl;
    }

    for (int i = 0; i < 7; ++i) {
        char szMessage[128] = {0,};
        sprintf_s(szMessage, 128 - 1, "%d - Send Message", i);
        size_t nMsgLen = strnlen_s(szMessage, 128 - 1);

        boost::system::error_code ignored_error;
        socket.write_some(boost::asio::buffer(szMessage, nMsgLen),
                          ignored_error);

        std::cout << "Sent: " << szMessage << std::endl;

        std::array<char, 128> buf;
        buf.fill(0);
        boost::system::error_code error;

        size_t len = socket.read_some(boost::asio::buffer(buf), error);

        if (error) {
            if (error == boost::asio::error::eof) {
                std::cout << "Disconnected with server." << std::endl;
            } else {
                std::cout << "error No: " << error.value()
                          << " error Message: " << error.message().c_str()
                          << std::endl;
            }

            break;
        }

        std::cout << "Receied: " << &buf[0] << std::endl;
    }

    if (socket.is_open()) {
        socket.close();
    }

    return 0;
}