/*
** EPITECH PROJECT, 2023
** Rtype
** File description:
** manipulate_byte
*/

#include "byte.hpp"

void ChangeBits::player_paquet(int idplayer, int move, int collide, int shoot)
{
    if (idplayer == 1)
        paquet <<= 1;
    if (idplayer == 2)
        (paquet <<= 1) |= 1;
    if (idplayer == 3)
        (paquet |= 1) <<= 1;
    if (idplayer == 4)
        ((paquet |= 1) <<= 1) |= 1;
    if (move == 1)
        (paquet <<= 4) |= 1;
    if (move == 2)
        ((paquet <<= 3) |= 1) <<= 1;
    if (move == 3)
        ((paquet <<= 2) |= 1) <<= 2;
    if (move == 4)
        ((paquet <<= 1) |= 1) <<= 3;
    if (collide == 0)
        paquet <<= 1;
    if (collide == 1)
        (paquet <<= 1) |= 1;
    if (shoot == 0)
        paquet <<= 1;
    if (shoot == 1)
        (paquet <<= 1) |= 1;
}

void ChangeBits::mob_paquet(int idennemis, int shoot, int move, int death)
{
    // if (idennemis == 1)
    //     paquet2 <<= 1;
    // if (idennemis == 2)
    //     (paquet2 <<= 1) |= 1;
    // if (idennemis == 3)
    //     (paquet2 |= 1) <<= 1;
    // if (idennemis == 4)
    //     ((paquet2 |= 1) <<= 1) |= 1;
    if (shoot == 0)
        paquet2 <<= 1;
    if (shoot == 1)
        (paquet2 <<= 1) |= 1;
    if (move == 1)
        (paquet2 <<= 4) |= 1;
    if (move == 2)
        ((paquet2 <<= 3) |= 1) <<= 1;
    if (move == 3)
        ((paquet2 <<= 2) |= 1) <<= 2;
    if (move == 4)
        ((paquet2 <<= 1) |= 1) <<= 3;
    if (death == 0)
        paquet2 <<= 1;
    if (death == 1)
        (paquet2 <<= 1) |= 1;
}

void ChangeBits::game_paquet(int endgame, int score)
{
    if (endgame == 0)
        paquet3 <<= 1;
    if (endgame == 1)
        (paquet3 <<= 1) |= 1;
    if (score == 1)
        (paquet3 <<= 4) |= 1;
    if (score == 2)
        ((paquet3 <<= 3) |= 1) <<= 1;
    if (score == 3)
        ((paquet3 <<= 2) |= 1) <<= 2;
    if (score == 4)
        ((paquet3 <<= 1) |= 1) <<= 3;
}