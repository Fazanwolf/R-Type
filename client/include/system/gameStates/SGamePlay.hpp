/*
** EPITECH PROJECT, 2023
** B-CPP-500-RUN-5-2-rtype-lucas.miranville
** File description:
** IGameState
*/

#pragma once

#include "IGameState.hpp"
#include <queue>
#include <array>
#include <string>
#include <cstring>
#include "Global.hpp"

using namespace rtype;
using namespace rtype::components;
/**
 * @brief The namespace of the SGamePlay
 * 
 */
namespace rtype::game {
    /**
     * @brief The class of the SGamePlay
     * 
     */
    class SGamePlay : public GameState {
        public:
            /**
             * @brief Construct a new SGamePlay object
             * 
             */
            SGamePlay()
            {
                this->name = "GamePlay";
                isMatchRunning = false;
            };

            /**
             * @brief Construct a new SGamePlay object
             * 
             * @param nb_players 
             */
            SGamePlay(int nb_players)
            {
                this->name = "GamePlay";
                isMatchRunning = false;
            };

            /**
             * @brief Destroy the SGamePlay object
             * 
             */
            ~SGamePlay()
            {
                gClt->disconnect();
            };

            void loadGameTexture(std::vector<std::string> paths)
            {
                int i = 0;
                for (auto p : paths) {
                    if (!textures[i++].loadFromFile(p))
                        std::cout << "error" << std::endl;
                }
            }

            void loadGameTexture(void)
            {
                if (!textures[0].loadFromFile("../assets/ovni.png"))
                    std::cout << "error" << std::endl;
            }

            void init_base(int nb_players)
            {
                for (int i = 0; i != nb_players; i++) {
                    this->EManager.NewEntity("./assets/ovni.png", {20, 30}, {0.3, 0.3});
                }
            }

            std::string getClientBuffer()
            {
                return gClt->getBuffer();
            }

            /**
             * @brief Init the game state
             *
             */
            void init() override
            {
                std::cout<<"Init Gameplay"<<std::endl;

//                loadGameTexture();

                std::string msg = gClt->getBuffer();

                while (msg.empty()) {
                    msg = gClt->getBuffer();
                    if (!msg.empty()) {
                        this->pID = std::stoi(msg);
                        this->EManager.setPId(this->pID);
                        std::cout << "Player ID: " << this->pID << std::endl;
                        init_base(2);
                        break;
                    }
                }

                msg = "";
                //init sprites;
                // this->shape.setFillColor(sf::Color::Green);
                // this->shape.setScale( {1.5,1.5} );
                // this->shape.setPosition( {20,30} );
                // this->shape.setTexture(textures[0]);

                this->CManager.Centipedeinit(300, 600, 50);
                this->BManager.initBackground("./assets/Nebula_Aqua-Pink.png", {1.5, 1.5});
                // this->EManager.NewEntity(textures[0], {20, 300}, {1.5, 1.5});
            };

            /**
             * @brief Update the game state
             *
             */
            void update() override
            {
                if (!isMatchRunning) {
                    //update button appearance etc
                    //update Status
                }
                this->CManager.update();
                //update match data & physics
                // update client to server data
                //pop event queue here after rework
            };

            /**
             * @brief Get the Local Player I D object
             *
             * @return int8_t
             */
            int8_t getLocalPlayerID() {return this->EManager.getPId();};

            /**
             * @brief Get the Local Player I D object
             *
             * @return int8_t
             */
            void setLocalPlayerID(int id) { this->EManager.setPId(id); };

            /**
             * @brief Handle the event input
             *
             * @param w
             * @param ev
             * @return int
             */
            int handleEvent(engine::Window &w, engine::Event &ev)
            {
                std::string str = getClientBuffer();

                int resLocalInput = LocalInput(ev);
                // std::cout<<"handleEvent"<<std::endl;
                this->EManager.handleEvent(ev);
                serverEvents(ev, str);
                return resLocalInput;
                // return (resLocalInput == -1 ? resLocalInput:rtype::STATES::NONE : resLocalInput);
            };

            /**
             * @brief Draw on the window
             *
             * @param g the window
             * @return int
             */
            void draw(rtype::engine::Window &w) override
            {
                //draw entities
                w.clear();
                this->BManager.draw(w.getWindow());
                this->EManager.draw(w.getWindow());
                this->CManager.draw(w.getWindow());
                for (auto &ammo : this->playerProj.getBulletList())
                    w.Draw(ammo);
                for (auto &ammo : this->serverProj.getBulletList())
                    w.Draw(ammo);
                // w.getWindow().draw(this->shape);
                //     w.Draw(this->EManager.getSprite(e));
                w.getWindow().display();
                // std::cout<<"draw"<<std::endl;
            };

            /**
             * @brief check Local Player input
             *
             * @param ev
             * @return int
             */
            //State Property
            int LocalInput(engine::Event &ev) //returns -1 if nothing to return
            {
                //keyboard Input
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
                {
                    return STATES::QUIT;
                }
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
                {
                    gClt->send(std::to_string(getLocalPlayerID()) + "fire");
                    //fire system
                }
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter) /*|| ready button pressed*/) {
                    gClt->send(std::to_string(getLocalPlayerID()) + "ready");
                    //send ready  info
                }
                // ev.MakeSpriteMovable(this->EManager.getSprite(0));
                return -1;
            }

            void serverEvents(engine::Event &ev, std::string &str) {
                auto tmp = str.empty()? std::vector<std::string>() : StringUtils::split(str, ' ');
                if (tmp.size() <= 1 || tmp[1].compare("?") == true) return;
                int eID = (this->pID == 1) ? 0:1;
                if (tmp[1].compare("0fire") == 0) {
                    // this->playerProj.ServerShootBullet(eID, )
                    std::cout<< "ok on est la" << std::endl;
                }
                if (tmp[1].compare("1fire") == 0)
                    std::cout << "2nd player shoot" << std::endl;
            }

        private:
            sf::Sprite shape;
            int pID;
            bool isMatchRunning; //when all player are ready set to true
            std::array<sf::Texture, 100> textures;
            rtype::components::Bullets playerProj;
            rtype::components::Bullets serverProj;
    };

}