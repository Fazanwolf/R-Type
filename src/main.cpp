#include "Rtype.hpp"

/**
 * SFML Code
 * Code to test SFML Library with cmake
 */
void sfml_test()
{
    sf::RenderWindow window(sf::VideoMode(800, 600), "SFML Test!");

    sf::Event event;
    while (window.isOpen())
    {
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        window.clear();
        window.display();
    }
}

int main(int ac, char **av)
{
    ncppl::ParserArgs parser(ac, av);

    parser.handler();
    spdlog::info("Welcome to spdlog!");

    boost::asio::io_service io; // Service principal

    boost::asio::deadline_timer t(io, boost::posix_time::seconds(5)); // Commence à compter dès sa création
    t.wait(); // On attend que le timer expire

    std::cout << "Terminé !" << std::endl;
    sfml_test();
    return 0;
}