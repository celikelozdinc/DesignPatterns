#ifndef BEHAVIORAL_TEMPLATE_METHOD_SOCKET_H
#define BEHAVIORAL_TEMPLATE_METHOD_SOCKET_H

#include <iostream>

struct Socket {
public:
    void Send() {
        OpenConnection();
        SendCustomData();
        CloseConnection();
    }

    Socket() {
        std::cout << "Socket::Socket()\n";
    }

    virtual ~Socket() {
        std::cout << "Socket::~Socket()\n";
    }

protected:
    virtual void SendCustomData() {
        std::cout << "Socket::SendCustomData()\n";
    }


private:
    void OpenConnection() {
        std::cout << "Socket::OpenConnection()\n";
    }

    void CloseConnection() {
        std::cout << "Socket::CloseConnection()\n";
    }
};


struct UnixDomainSocket : Socket {
protected:
    void SendCustomData() override {
        std::cout << "UnixDomainSocket::SendCustomData()\n";
    }
public:
    UnixDomainSocket() {
        std::cout << "UnixDomainSocket::UnixDomainSocket()\n";
    }

    ~UnixDomainSocket() {
        std::cout << "UnixDomainSocket::~UnixDomainSocket()\n";
    }
};


struct UDPSocket : Socket {
protected:
    void SendCustomData() override {
        std::cout << "UDPSocket::SendCustomData()\n";
        std::cout << "Adding one more step:\n";
        Socket::SendCustomData();
    }
public:
    UDPSocket() {
        std::cout << "UDPSocket::UDPSocket()\n";
    }

    ~UDPSocket() {
        std::cout << "UDPSocket::~UDPSocket()\n";
    }
};

#endif  // BEHAVIORAL_TEMPLATEMETHOD_SOCKET_H_
