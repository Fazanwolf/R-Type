/*
** EPITECH PROJECT, 2023
** B-CPP-500-RUN-5-2-rtype-lucas.miranville
** File description:
** main
*/

#include "Engine/Engine.hpp"
#include "Engine/Error.hpp"
#include "system/gameStates/SGamePlay.hpp"
#include "system/GameEngine.hpp"

#include "system/GameArchi.hpp"

int main(void)
{
    try {
        // rtype::engine::StateManager state;
        // rtype::engine::Window win;
        // rtype::GameEngine g;
        rtype::GameArchi archi;
        // g.clt = new sk::Skaldi<sk::client::UDP, sk::server::UDP>("0.0.0.0", "5000");
        // g.clt->client->setFirstConnection(true);
        // g.clt->client->firstConnection("?");

        // std::thread t([&]() {
        archi.CreateWindow({920, 620}, "R-Type");
        // archi.CreateEntities("assets/mario.png", {200, 200}, {0.1, 0.1});
            // g.createWindow();
            // g.init();
            // while (g.win.IsOpen())
            // {
            //     g.handleEvent();
            //     g.update();
            //     g.draw();
            // }
            while (archi.IsOpen()) {
                while (archi.UpdateEvent()) {
                    // Do your Event
                    if (archi.HandleEvent(sf::Event::Closed))
                        archi.CloseWindow();
                }
                archi.ClearWindow();
                archi.DisplayWindow();
            }
        // });
        // t.detach();
        // g.clt->run();
    } catch (Error &error) {
        std::cerr << error.what() << std::endl;
        return (84);
    }
    return (0);
}