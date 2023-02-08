/*
** EPITECH PROJECT, 2023
** B-CPP-500-RUN-5-2-rtype-lucas.miranville
** File description:
** Error
*/

#include "Engine/Error.hpp"

Error::Error(std::string msg)
{
    this->_msg = msg;
}

Error::~Error()
{
}
