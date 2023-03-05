#include "Server.hpp"

int main(int ac, char **av)
{
    if (ac != 2 || !utilities::Check::isPort(av[1])) {
        std::cerr << "Usage: ./server [port]" << std::endl;
        return (-84);
    }
    const unsigned short port = static_cast<unsigned short>(std::stoi(av[1]));
    sk::Server<sk::server::UDP> server(port);
    server.setBroadcasting(true);
    server.getInput();
    server.run();
    return 0;
}