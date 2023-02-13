/*
** EPITECH PROJECT, 2023
** B-CPP-500-RUN-5-2-rtype-lucas.miranville
** File description:
** main
*/

#include "Server.hpp"

int main(int ac, char **av)
{
    if (ac != 2 || !utilities::Check::isPort(av[1])) {
        std::cerr << "Usage: ./server port" << std::endl;
        return (-84);
    }
    sk::Server<sk::server::UDP> server(std::stoi(av[1]));
    server.setBroadcasting(true);
    server.getInput();
    server.run();
    return (0);
}
