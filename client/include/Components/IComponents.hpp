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

            void printSMthing(std::string str) { std::cout<<str<<std::endl;}

            void draw(sf::RenderWindow &w) override {}
            void update() override {}
            void init() override {}

            int8_t getId() { return Id; }
            int8_t getOwnerId() { return OwnerId; }
    };

    class DefaultComp : public Component
    {

        public:
            DefaultComp() {}
            ~DefaultComp() {}

            DefaultComp(sf::Texture &tex, sf::Vector2f pos, sf::Vector2f size) {

                // this->assetTexture = tex;
                asset.setTexture(tex);
                asset.scale(this->scale);
                asset.setPosition(this->pos);
            }

            void DefaultCmp(std::string file, sf::Vector2f pos, sf::Vector2f size) {

                // this->assetTexture = tex;
                std::cout<<"bon_èè-è-è_è_-è"<< std::endl;
                if (!this->assetTexture.loadFromFile(file))
                    std::cout << "error" << std::endl;
                this->asset.setTexture(this->assetTexture);
                this->asset.scale(size);
                this->asset.setPosition(pos);
            }

            sf::Sprite &getSprite(void) {
                std::cout << "fsdflsdnfjkdfnksjdfjkds " << std::endl;
                return this->asset;
            }

            void draw(sf::RenderWindow &w) {
                std::cout<<"fuck that\n";
                w.draw(this->asset);
                std::cout << "DO SMGT" << std::endl;
            }

            private:
                sf::Sprite asset;
                sf::Texture assetTexture;
                sf::Vector2f pos;
                sf::Vector2f scale;
                sf::IntRect textRect;
    };

} // namespace rtype::Components

#endif /* !COMPONENTS_HPP_ */