/*
** EPITECH PROJECT, 2023
** Rtype
** File description:
** byte
*/

#ifndef BYTE_HPP_
#define BYTE_HPP_

#include <iostream>
#include <bitset>
#include <vector>
#include <boost/asio.hpp>

class ChangeBits
{
    public:
        std::string move_bits;
        int paquet = 0;
        int idenemy = 0;
        int paquet2 = 0;
        int paquet3 = 0;

        ChangeBits();
        ~ChangeBits();

        void player_paquet(int idplayer, int move, int collide, int shoot);
        void mob_paquet(int idennemis, int shoot, int move, int death);
        void game_paquet(int endgame, int score);
};

ChangeBits::ChangeBits()
{
}

ChangeBits::~ChangeBits()
{
}

#endif /* !BYTE_HPP_ */
