/*
** EPITECH PROJECT, 2023
** R-Type
** File description:
** Stest
*/

#ifndef STEST_HPP_
#define STEST_HPP_
#include "IGameState.hpp"
#include "Components/Bouton.hpp"

namespace rtype::game
{

class SMenu : public GameState {
    public:
        std::string getName(){
            return name;
        }
        SMenu() {
            this->name = "Menu";
        };
        ~SMenu() {};
        void init() override {
            return;}

        void update() override {return;}

        int handleEvent(rtype::engine::Window &w,  engine::Event &ev) override {
            w;
            sf::Event ed;
            ev.GetMousePos(ed);
            return 0;
        };
        void draw(rtype::engine::Window &w) override
        {
            w.clear();
            this->EManager.Draw();
            w.getWindow().display();
        };
    protected:
        std::string name;
};
}
#endif /* !STEST_HPP_ */
