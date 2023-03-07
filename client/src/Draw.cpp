/*
** EPITECH PROJECT, 2023
** B-CPP-500-RUN-5-2-rtype-lucas.miranville
** File description:
** Draw
*/

#include "Engine/Draw.hpp"

using namespace rtype::engine;

Draw::Draw()
{
}

Draw::~Draw()
{
}

sf::RectangleShape Draw::DrawRectangle(int height, int width, sf::Vector2f pos)
{
    sf::RectangleShape rectangle(sf::Vector2f(height, width));

    rectangle.setPosition(pos);
    return rectangle;
}

sf::CircleShape Draw::DrawSphere(int radius)
{
    sf::CircleShape shape(radius);

    return shape;
}

void Draw::SetTextureToCircle(sf::CircleShape circle, sf::Texture texture, sf::IntRect posRect)
{
    circle.setTexture(&texture);
    circle.setTextureRect(posRect);
}

void Draw::SetTextureToRectangle(sf::RectangleShape rectangle, sf::Texture texture, sf::IntRect posRect)
{
    rectangle.setTexture(&texture);
    rectangle.setTextureRect(posRect);
}
