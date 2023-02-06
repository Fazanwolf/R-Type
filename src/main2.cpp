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

int main()
{
    Skaldi::Skaldi g = Skaldi::Skaldi();
    g.createUDPServer(5000);
    sfml_test();
    return 0;
}