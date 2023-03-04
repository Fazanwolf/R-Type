/*
** EPITECH PROJECT, 2023
** B-CPP-500-RUN-5-2-rtype-lucas.miranville
** File description:
** IGameState
*/

#include "system/gameStates/IGameState.hpp"
#include <queue>
#include <string>
#include <cstring>
#include <Skaldi.hpp>

#ifndef SGAMEPLAY_HPP_
#define SGAMEPLAY_HPP_

using namespace rtype;

namespace rtype::game {

    class SGamePlay : public GameState {
        public:
            SGamePlay()
            {

            };

            ~SGamePlay()
            {

            };

            void init_base(int nbPlayers, int nbnemies) {
                //players
                for (int i = 0; i != nbPlayers; i++)
                    this->EManager.NewEntity("./assets/ovni.png", false);
                // FirstEntities
                // for (int i = 0; i != nbnemies; i++)
                    // this->EManager.spawnEnemy("./assets/ovni.png", true);
            }

            void init() override
            {
                //init sprites;
                // init_base(2, 1);
            };

            void init(int pID, int nbPlayers, int nbEnemies)
            {
                //init sprites;
                this->EManager.setPId(pID);
                this->pID = pID;
                init_base(nbPlayers, nbEnemies);
                event_queue.push(engine::NONE);
            };

            void update() override
            {
                // update client to server data
                //pop event queue here after rework
                if (playerProjectile.update(EManager.getSprite(2).getGlobalBounds())) {
                    EManager.getSprite(2).setScale(sf::Vector2f(0,0));
                }
                if (serverProjectiles.update(EManager.getSprite(2).getGlobalBounds())) {
                    EManager.getSprite(2).setScale(sf::Vector2f(0,0));
                }
                this->EManager.updateEnemies("./assets/ovni.png", true);
            };

            void clear() override
            {
                return;//later
            };

            void pause() override {}; //later
            void resume() override {}; //later

            int8_t getLocalPlayerID() {return this->EManager.getPId();};

            void playerEvent(engine::Event &ev)
            {
                if (pID == 1)
                    ev.MakeSpriteMovable_Bis(EManager.getSprite(this->pID)); // idx 0 == player character
                else
                    ev.MakeSpriteMovable(EManager.getSprite(this->pID)); // idx 0 == player character
                if (this->playerProjectile.ShootBullet(pID, EManager.getSprite(this->pID)) == true)
                    ev.sendMessage("fire") ;
            }

            void serverEvents(engine::Event &ev, std::string &str)
            {
                // std::cout<<str<<" | start test tmp:"<<str<<":"<<std::endl;
                auto tmp = str.empty()? std::vector<std::string>() : StringUtils::split(str, ' ');
                if (tmp.size() <= 1 || tmp[1].compare("?") == true) return;
                int eID = (pID == 1) ? 0:1;
                //if (eID == pID) return;
                std::cout<<str<<" | mid tmp:"<<tmp[1]<<":"<<std::endl;
                if (std::strcmp(tmp[1].c_str() ,"move") == 0)
                {
                    if (tmp[2].compare("left") == 0)
                        EManager.getSprite(eID).move(sf::Vector2f{-50, 0});
                    //    event_queue.push(engine::MV_LEFT);
                    if (tmp[2].compare("right") == 0)
                        EManager.getSprite(eID).move(sf::Vector2f{50, 0});
                    //    event_queue.push(engine::MV_RIGHT);
                    if (tmp[2].compare("up") == 0)
                        EManager.getSprite(eID).move(sf::Vector2f{0, -50});
                    //    event_queue.push(engine::MV_UP);
                    if (tmp[2].compare("down") == 0)
                        EManager.getSprite(eID).move(sf::Vector2f{0, 50});
                    std::cout<<"direction: "<<tmp[2]<<std::endl;

                } else if (tmp[1].compare("fire") == 0)
                    this->serverProjectiles.ServerShootBullet(eID, EManager.getSprite(eID));
                    //event_queue.push(engine::FIRE);
                // std::cout<<eID<<" tmp: "<<tmp[1]<<std::endl;
                // if (!event_queue.empty()) {
                //     if (ev.ServerPlayerAction(EManager.getSprite(eID), event_queue.front()) == engine::FIRE)
                //     // event_queue.pop();
                //     // ev.ServerPlayerAction(EManager.getSprite(eID), event_queue.front());
                // }
            }

            int handleEvent(rtype::engine::Window &w, engine::Event &ev)
            {
                //retrieve and handle server input here
                std::string str = ev.getClientBuffer();
                serverEvents(ev, str);
                playerEvent(ev);
                return 0;
            };

            void draw(rtype::engine::Window &w) override
            {
                //draw entities
                for (auto& e : this->EManager.getIDs())
                    w.Draw(this->EManager.getSprite(e));
                for (auto& e : this->EManager.getIDs())
                    w.Draw(this->EManager.getSpriteE(e));
                for (auto& ammo : playerProjectile.getBulletList())
                    w.Draw(ammo);
                for (auto& ammo : serverProjectiles.getBulletList())
                    w.Draw(ammo);
            };

        private:
            int8_t pID;
            std::queue<rtype::engine::EventType> event_queue;
            rtype::components::Bullets playerProjectile;
            rtype::components::Bullets serverProjectiles;
    };
}

#endif /* !SGAMEPLAY_HPP_ */