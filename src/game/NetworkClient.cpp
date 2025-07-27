#include "NetworkClient.h"

namespace hydra {

NetworkClient::NetworkClient() {
    WSADATA wsaData;
    WSAStartup(MAKEWORD(2,2), &wsaData);
}

NetworkClient::~NetworkClient() {
    disconnect();
    WSACleanup();
}

bool NetworkClient::connect(const std::string& host, unsigned short port) {
    m_socket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
    if (m_socket == INVALID_SOCKET) return false;

    sockaddr_in addr{};
    addr.sin_family = AF_INET;
    addr.sin_port = htons(port);
    addr.sin_addr.s_addr = inet_addr(host.c_str());
    if (::connect(m_socket, reinterpret_cast<sockaddr*>(&addr), sizeof(addr)) != 0)
        return false;
    return handshake();
}

bool NetworkClient::handshake() {
    const char* msg = "HELLO";
    int len = static_cast<int>(strlen(msg));
    if (send(m_socket, msg, len, 0) != len)
        return false;
    char buf[6] = {};
    int rec = recv(m_socket, buf, 5, 0);
    return rec > 0;
}

void NetworkClient::disconnect() {
    if (m_socket != INVALID_SOCKET) {
        closesocket(m_socket);
        m_socket = INVALID_SOCKET;
    }
}

} // namespace hydra
