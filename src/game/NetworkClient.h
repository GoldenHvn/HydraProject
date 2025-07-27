#ifndef HYDRA_NETWORKCLIENT_H
#define HYDRA_NETWORKCLIENT_H

#include <winsock2.h>
#include <string>

#pragma comment(lib, "ws2_32.lib")

namespace hydra {

class NetworkClient {
public:
    NetworkClient();
    ~NetworkClient();

    bool connect(const std::string& host, unsigned short port);
    bool handshake();
    void disconnect();

private:
    SOCKET m_socket = INVALID_SOCKET;
};

} // namespace hydra

#endif // HYDRA_NETWORKCLIENT_H
