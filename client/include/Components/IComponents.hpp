/*
** EPITECH PROJECT, 2023
** R-Type
** File description:
** Components
*/

#pragma once

#include "Engine/Engine.hpp"

namespace rtype
{
    // template <typename T>
    // class SparseArray
    // {
    //   protected:
    //     std::vector<std::size_t> inUse;
    //     std::vector<T> elems;

    //   public:
    //     SparseArray() {}
    //     ~SparseArray() {}

    //     void setVector(std::vector<T> newList) {
    //       elems = newList;
    //     }

    //     void addElem(T elem) {

    //        elems.push_back(elem);
    //     }

    //     void insertAt(T elem, int idx) {
    //       // if (elems.size() = idx) //si
    //       //   elems.insert
    //         elems.insert(elems.begin()+idx);
    //         if (elems.size() < idx-1)
    //           return;

    //     }

    //     void removeElem(int idx) {
    //       elems.erase(this->elems.begin()+idx);
    //     }

    //     void updateElem(T *elem, int idx) { elems[idx] = elem; }

    //     //getter
    //     T getElemAt(int idx) { return elems[idx]; }

    //     T front() { return elems.front(); }

    //     T back() { return elems.back(); }

    //     std::vector<T> getList() { return this->elems; }
    // };
}

namespace rtype::components
{   

    class IComponents {
        public:
            virtual void draw(sf::RenderWindow &w) = 0;
            virtual void update() = 0;
            virtual void init() = 0;
            virtual int8_t getId() = 0;
            virtual int8_t getOwnerId() = 0;
            virtual int handleEvent(rtype::engine::Event &handler) = 0;
            virtual int handleEvent() = 0;

    };

    class Component : public IComponents
    {
        public:
            int8_t Id;
            int8_t OwnerId;
            std::string name;
            
            Component() {}
            Component(int8_t id, int8_t Oid) {
                name = "default";
                this->Id = id;
                this->OwnerId = Oid;
            }

            ~Component() {}

            void pName() {
                std::cout<<this->name<<std::endl;
            }

            void printSMthing(std::string str) { std::cout<<str<<std::endl;}
            int handleEvent(rtype::engine::Event &handler) override {return -1;};
            int handleEvent() override {}

            virtual void draw(sf::RenderWindow &w) override { std::cout<<"Fuck me\n";}
            virtual void update() override {}
            virtual void init() override {}

            int8_t getId() { return Id; }
            int8_t getOwnerId() { return OwnerId; }
    };

    class DefaultComp : public Component
    {
        public:
            sf::Sprite asset;
            sf::RectangleShape shape;
            sf::Texture assetTexture;
            sf::Vector2f pos;
            sf::Vector2f scale;
            sf::IntRect textRect;
            bool localPlayer;
        public:
            DefaultComp() {}
            ~DefaultComp() {}

            DefaultComp(sf::Texture &tex, sf::Vector2f spawnPos, sf::Vector2f spawnSize, bool status) {
                this->name = "DefComp";
                this->scale = spawnSize;
                this->pos = spawnPos;
                localPlayer = status;

                this->shape.setFillColor(sf::Color::Green);
                this->shape.setPosition(this->pos);
                this->shape.setSize(this->scale);

                this->assetTexture = tex;
                asset.setTexture(assetTexture); 
                asset.setScale(this->scale);
                asset.setPosition(this->pos);
            }

            DefaultComp(std::string tex, sf::Vector2f spawnPos, sf::Vector2f spawnSize, bool status) {
                this->name = "DefComp";
                this->scale = spawnSize;
                this->pos = spawnPos;
                localPlayer = status;

                this->shape.setFillColor(sf::Color::Green);
                this->shape.setPosition(this->pos);
                this->shape.setSize(this->scale);

                sf::Sprite tmp;

                if (!assetTexture.loadFromFile(tex))
                    std::cout << "error" << std::endl;                

                tmp.setTexture(this->assetTexture);
                tmp.setScale(this->scale);
                tmp.setPosition(this->pos);
                this->asset = tmp;

            }

            void draw(sf::RenderWindow &w) override{
                // std::cout<<"fuck that in defComp\n";
                // w.draw(this->shape);
                w.draw(this->asset);
            }
            
            int handleEvent(rtype::engine::Event &handler) override {
                handler.MakeObjectMovable(this->asset);
                return 0;
            }

            int handleEvent() override {
                std::cout<<"dang it\n";
                return 0;
            };
    };

} // namespace rtype::Components