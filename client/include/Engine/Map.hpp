/*
** EPITECH PROJECT, 2023
** B-CPP-500-RUN-5-2-rtype-lucas.miranville
** File description:
** Map
*/

#ifndef MAP_HPP_
#define MAP_HPP_

#include "Engine/Engine.hpp"

/**
* @brief This namespace is for herite from engine
*/
namespace rtype::engine {

#include <SFML/Graphics.hpp>
#include <fstream>
#include <iostream>

//size of a tile
const int TILE_SIZE = 32;
const float PLAYER_SPEED = 100.0f;

class Map {
    public:
        Map() :
           // m_window(sf::VideoMode(500,400), "Tilemap"),
           // m_playerTexture(),
           // m_playerSprite(),
            m_clock(),
            m_tilemap(nullptr),
            m_numRows(0),
            m_numCols(0)
        {
        }

        bool loadTilemapFromFile(const std::string& filename) {
            std::ifstream tilemapFile(filename);
            if (!tilemapFile.is_open()) {
                std::cerr << "Failed to open tilemap file\n";
                return false;
            }

            tilemapFile >> m_numRows >> m_numCols;

            m_tilemap = new int*[m_numRows];
            for (int i = 0; i < m_numRows; i++) {
                m_tilemap[i] = new int[m_numCols];
                for (int j = 0; j < m_numCols; j++) {
                    tilemapFile >> m_tilemap[i][j];
                }
            }
            tilemapFile.close();

            return true;
        }

        bool loadTilesetTextureFromFile(const std::string& filename) {
            if (!m_tilesetTexture.loadFromFile(filename)) {
                std::cerr << "Failed to load tileset image\n";
                return false;
            }

            m_tilesetSprite.setTexture(m_tilesetTexture);

            return true;
        }

        bool loadPlayerTextureFromFile(const std::string& filename) {
            if (!m_playerTexture.loadFromFile(filename)) {
                std::cerr << "Failed to load player image\n";
                return false;
            }

            m_playerSprite.setTexture(m_playerTexture);
            m_playerSprite.setPosition(0, 0);

            return true;
        }

        int initMap(/*const std::string& filenatilemaptxt, const std::string& tilesetpng const std::string& filename*/) {
            if (!loadTilemapFromFile("./assets/tilemap.txt")) {
                return 1;
            }

            if (!loadTilesetTextureFromFile("./assets/tileset.png")) {
                return 1;
            }

          //  if (!map.loadPlayerTextureFromFile("player.png")) {
          //      return 1;
          //  }
        }

     //   void run() {
     //       while (m_window.isOpen()) {
     //           handleEvents();
     //           update();
     //           render();
     //       }
     //   }

  //  private:
     //   void handleEvents() {
     //       sf::Event event;
     //       while (m_window.pollEvent(event)) {
     //           if (event.type == sf::Event::Closed)
     //               m_window.close();
     //       }
     //   }


        //utilisé mais ne sert a rien actuellement car pas de player
        void update() {
            float deltaTime = m_clock.restart().asSeconds();

            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
                m_playerSprite.move(-PLAYER_SPEED * deltaTime, 0);
            } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
                m_playerSprite.move(PLAYER_SPEED * deltaTime, 0);
            } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
                m_playerSprite.move(0, -PLAYER_SPEED * deltaTime);
            } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
                m_playerSprite.move(0, PLAYER_SPEED * deltaTime);
            }

            checkCollisionsWithTilemap();
        }
//fonction bien dev mais n'est pas utilié
    void checkCollisionsWithTilemap() {
        sf::FloatRect playerBounds = m_playerSprite.getGlobalBounds();
        sf::Vector2f playerPos = m_playerSprite.getPosition();
        for (int i = 0; i < m_numRows; i++) {
            for (int j = 0; j < m_numCols; j++) {
                int tileIndex = m_tilemap[i][j];
                int tileX = tileIndex % 5;
                int tileY = tileIndex / 5;

                if (tileIndex == 1) { // Solid tile
                    sf::FloatRect tileBounds(j * TILE_SIZE, i * TILE_SIZE, TILE_SIZE, TILE_SIZE);

                    if (playerBounds.intersects(tileBounds)) {
                        sf::Vector2f playerPos = m_playerSprite.getPosition();
                        if (playerPos.x + playerBounds.width > tileBounds.left && playerPos.x < tileBounds.left) {
                            playerPos.x = tileBounds.left - playerBounds.width;
                        }
                        if (playerPos.x < tileBounds.left + tileBounds.width && playerPos.x + playerBounds.width > tileBounds.left + tileBounds.width) {
                            playerPos.x = tileBounds.left + tileBounds.width;
                        }
                        if (playerPos.y + playerBounds.height > tileBounds.top && playerPos.y < tileBounds.top) {
                            playerPos.y = tileBounds.top - playerBounds.height;
                        }
                        if (playerPos.y < tileBounds.top + tileBounds.height && playerPos.y + playerBounds.height > tileBounds.top + tileBounds.height) {
                            playerPos.y = tileBounds.top + tileBounds.height;
                        }
                        m_playerSprite.setPosition(playerPos);
                    }
                }
            }
        }
    }

    void render(sf::RenderWindow& m_window) {
       // m_window.clear();

        // Draw tilemap
        for (int i = 0; i < m_numRows; i++) {
            for (int j = 0; j < m_numCols; j++) {
                int tileIndex = m_tilemap[i][j];
                //Choose x & y for your tilemap.png
                int tileX = tileIndex % 8;
                int tileY = tileIndex / 8;

                m_tilesetSprite.setTextureRect(sf::IntRect(tileX * TILE_SIZE, tileY * TILE_SIZE, TILE_SIZE, TILE_SIZE));
                m_tilesetSprite.setPosition(j * TILE_SIZE, i * TILE_SIZE);

                m_window.draw(m_tilesetSprite);
            }
        }

        // Draw player
      //  m_window.draw(m_playerSprite);

       // m_window.display();
    }
    private:
        sf::RenderWindow m_window;
        sf::Texture m_tilesetTexture;
        sf::Sprite m_tilesetSprite;
        sf::Texture m_playerTexture;
        sf::Sprite m_playerSprite;
        sf::Clock m_clock;
        int** m_tilemap;
        int m_numRows;
        int m_numCols;
    };




//MAIN
// int main() {
// Game game;

// if (!game.loadTilemapFromFile("tilemap.txt")) {
//     return 1;
// }

// if (!game.loadTilesetTextureFromFile("tileset.png")) {
//     return 1;
// }

// if (!game.loadPlayerTextureFromFile("player.png")) {
//     return 1;
// }

// game.run();

// return 0;
// }





//--------------------------------------------------------------
   //     protected:
   //     private:
   //         sf::Vector2f m_map;
   //         sf::Vector2f m_collision;
   // };
}

#endif /* !MAP_HPP_ */
