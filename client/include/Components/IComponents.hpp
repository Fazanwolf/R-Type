/*
** EPITECH PROJECT, 2023
** R-Type
** File description:
** Components
*/

#ifndef COMPONENTS_HPP_
#define COMPONENTS_HPP_

#include "Engine/Engine.hpp"

namespace rtype
{

    template <typename T>
    class SparseArray
    {
      protected:
        std::vector<T> elems;

      public:
        SparseArray() {}
        ~SparseArray() {}

        void setVector(std::vector<T> newList) {
          elems = newList;
        }

        void addElem(T elem) {
           elems.push_back(elem);
        }

        void insertAt(T elem, int idx) {
          // if (elems.size() = idx) //si
          //   elems.insert
          if (elems.size() < idx-1)
              return;
        }

        void removeElem(int idx) {
          elems.erase(this->elems.begin()+idx);
        }

        void updateElem(T *elem, int idx) { elems[idx] = elem; }

        //getter
        T getElemAt(int idx) { return elems[idx]; }

        T front() { return elems.front(); }

        T back() { return elems.back(); }

        std::vector<T> getList() { return this->elems; }
    };
}

namespace rtype::components
{   

    class IComponents {
        public:
            virtual void draw(sf::RenderWindow &w) = 0;
            virtual void update() = 0;
            virtual void init() = 0;
    
    };

    class Component : public IComponents
    {
        public:
            int8_t Id;
            int8_t OwnerId;
            
            Component() {}
            Component(int8_t id, int8_t Oid) {
                this->Id = id;
                this->OwnerId = Oid;
            }

            ~Component() {}

            void draw(sf::RenderWindow &w) override {}
            void update() override {}
            void init() override {}

            int8_t getId() { return Id; }
            int8_t getOwnerId() { return OwnerId; }
    };

    class Default : public Component
    {
        public:
            sf::Sprite asset;
            sf::Texture assetTexture;
            sf::Vector2f pos;
            sf::Vector2f scale;
            sf::IntRect textRect;

        public:
            Default() {}
            ~Default() {}

            Default(sf::Texture &tex, sf::Vector2f pos, sf::Vector2f size) {

                this->assetTexture = tex;
                asset.setTexture(this->assetTexture);
                asset.setScale(this->scale);
                asset.setPosition(this->pos);
            }

            void draw(sf::RenderWindow &w) {
                w.draw(asset);
            }
    };

} // namespace rtype::Components

#endif /* !COMPONENTS_HPP_ */