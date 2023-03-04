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

int main(void)
{
    try {
        // rtype::engine::StateManager state;
        // rtype::engine::Window win;
        rtype::entities::EntitiesManager ent;
        rtype::GameEngine g;
        g.clt = new sk::Skaldi<sk::client::UDP, sk::server::UDP>("0.0.0.0", "5000");
        g.clt->client->setFirstConnection(true);
        g.clt->client->firstConnection("?");

        std::thread t([&]() {
            g.createWindow();
            g.init(2, "assets/ovni.png", 0);
            g.makeEnemies(50, "assets/truc.png", 1);
            while (g.win.IsOpen()) {
                g.handleEvent();
                g.update();
                g.draw();
            }
        });
        t.detach();
        g.clt->run();
    } catch (Error &error) {
        std::cerr << error.what() << std::endl;
        return (84);
    }
    return (0);
}