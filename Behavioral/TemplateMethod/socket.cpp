#include "socket.h"

#include <memory>

int main() {
    std::cout << "*******************************************\n";
    std::unique_ptr<Socket> uds = std::make_unique<UnixDomainSocket>();
    uds->Send();
    std::cout << "*******************************************\n";
    std::unique_ptr<Socket> udp = std::make_unique<UDPSocket>();
    udp->Send();
    std::cout << "*******************************************\n";
    return EXIT_SUCCESS;
}