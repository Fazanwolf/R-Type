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
using namespace rtype::components;

namespace rtype::game {

    class SGamePlay : public GameState {
        public:
            SGamePlay()
            {
                this->name = "GamePlay";
                this->isMatchRunning = false;
            };

            ~SGamePlay()
            {

            };

            SGamePlay(int nb_players)
            {
                this->name = "GamePlay";
                isMatchRunning = false;
            }

            void init_base(int nb_players) {
                //players
                for (int i = 0; i != nb_players; i++)
                    this->EManager.NewEntity("./assets/ovni.png", {100, 100}, {0.1, 0.1});
                //FirstEntities
                this->EManager.NewMobs("./assets/ovni.png", {520, 480}, {0.2, 0.2});
                this->EManager.NewMobs("./assets/ovni.png", {420, 500}, {0.2, 0.2});
                this->EManager.NewMobs("./assets/ovni.png", {520, 420}, {0.2, 0.2});
                this->EManager.NewMobs("./assets/ovni.png", {620, 320}, {0.2, 0.2});

            }

            void init() override
            {
                //init sprites;
                init_base(2);
            };

            void init(int pID)
            {
                //init sprites;
                this->EManager.setPId(pID);
                this->CManager.Centipedeinit(300, 600, 50);
                this->BManager.initBackground("./assets/Nebula.png", {1.5, 1.5});
                this->pID = pID;
                init_base(2);
                event_queue.push(engine::NONE);
            };

            void update() override
            {
                // update client to server data
                //pop event queue here after rework
                for (auto& e : this->EManager.getIDsM()) {
                    if (playerProjectile.update(EManager.getSpriteM(e).getGlobalBounds())) {
                        EManager.getSpriteM(e).setScale(sf::Vector2f(0,0));
                    }
                    if (serverProjectiles.update(EManager.getSpriteM(e).getGlobalBounds())) {
                        EManager.getSpriteM(e).setScale(sf::Vector2f(0,0));
                    }
                }
                // if (playerProjectile.update(BlManager.getShape())) {
                //     BlManager.getShape().setRadius(0);
                // }
                // if (serverProjectiles.update(BlManager.getShape())) {
                //     BlManager.getShape().setRadius(0);
                // }
                this->CManager.update();
            };

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
                LocalInput(ev);
                return 0;
            };

            void draw(rtype::engine::Window &w) override
            {
                //draw entities
                this->BManager.draw(w.getWindow());
                for (auto& e : this->EManager.getIDs())
                    w.Draw(this->EManager.getSprite(e));
                for (auto& e : this->EManager.getIDsM())
                    w.Draw(this->EManager.getSpriteM(e));
                for (auto& ammo : playerProjectile.getBulletList())
                    w.Draw(ammo);
                for (auto& ammo : serverProjectiles.getBulletList())
                    w.Draw(ammo);
                this->CManager.draw(w.getWindow());
            };

            int LocalInput(engine::Event &ev) {
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {
                    return STATES::QUIT;
                }
                return -1;
            }

        private:
            int8_t pID;
            bool isMatchRunning;
            std::queue<rtype::engine::EventType> event_queue;
            rtype::components::Bullets playerProjectile;
            rtype::components::Bullets serverProjectiles;
    };

}

#endif /* !SGAMEPLAY_HPP_ */