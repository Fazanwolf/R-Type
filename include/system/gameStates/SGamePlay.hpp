/*
** EPITECH PROJECT, 2023
** B-CPP-500-RUN-5-2-rtype-lucas.miranville
** File description:
** IGameState
*/

#include "system/gameStates/IGameState.hpp"
#include <Skaldi.hpp>

#ifndef SGAMEPLAY_HPP_
#define SGAMEPLAY_HPP_

namespace rtype::game {

    class SGamePlay : public GameState {
        public:
            SGamePlay()
            {

            };

            ~SGamePlay()
            {

            };

            void init_base(int nb_players) {
                //players
                for (int i = 0; i != nb_players; i++)
                    this->EManager.NewEntity("./assets/ovni.png", {100, 100}, {0.1, 0.1});
                //FirstEntities
                this->EManager.NewEntity("./assets/ovni.png", {600, 100}, {0.2, 0.2});
            }

            void init() override
            {
                //init sprites;
                init_base(2);
            };

            void update() override
            {
                // update client to server data
                if (playerProjectile.update(EManager.getSprite(2).getGlobalBounds())) {
                    EManager.getSprite(2).setScale(sf::Vector2f(0,0));
                }
            };

            void clear() override
            {
                return;//later
            };

            void pause() override {}; //later
            void resume() override {}; //later

            int handleEvent(rtype::engine::Window &w, engine::Event &ev, sk::Skaldi<sk::client::UDP, sk::server::UDP> &clt)
            {
                //retrieve and handle server input here
//                while (w.UpdateEvent())
//                {
                    ev.MakeSpriteMovable(EManager.getSprite(0)); // idx 0 == player character
                    this->playerProjectile.ShootBullet(EManager.getSprite(0));
                    clt.client->send("test");
                    //close window
//                }
                return 0;
            };

            void draw(rtype::engine::Window &w) override
            {
                //draw entities
                for (auto& e : this->EManager.getIDs())
                    w.Draw(this->EManager.getSprite(e));
                for (auto& ammo : playerProjectile.getBulletList())
                    w.Draw(ammo);
            };

        private:
            rtype::components::Bullets playerProjectile;

    };

}

#endif /* !SGAMEPLAY_HPP_ */