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
        rtype::GameEngine g;
//        std::thread t([&]() {
            g.clt = new sk::Skaldi<sk::client::UDP, sk::server::UDP>("0.0.0.0", "5000");
            g.clt->client->receive();
            g.clt->client->setDebugging(false);
            g.clt->client->setFirstConnection(true);
            g.clt->client->firstConnection("?");
//        });
//        t.detach();

         // state.GameRun();
        // while (win.IsOpen()) {
        //     win.UpdateEvent();
        // }
        // state.GameRun();

        std::thread t([&]() {
            g.createWindow();
            g.init();
            while (g.win.IsOpen()) {
                g.handleEvent();
                g.update();
                g.draw();
                g.clt->client->receive();
                spdlog::info("msg: {}", g.clt->client->getBuffer());
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
