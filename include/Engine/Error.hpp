/*
** EPITECH PROJECT, 2023
** B-CPP-500-RUN-5-2-rtype-lucas.miranville
** File description:
** Error
*/

#ifndef ERROR_HPP_
#define ERROR_HPP_

#include "Engine.hpp"
#include <exception>
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <iosfwd>
#include <regex>
#include <stdbool.h>

class Error : std::exception {
    public:
        Error(std::string msg) {
            this->_msg = msg;
        };
        ~Error() = default;

        const char *what() const throw() {
            return this->_msg.c_str();
        }

    protected:
    private:
        std::string _msg;
};

class LoadError : std::exception {
    public:
        LoadError(std::string msg) {
            this->_msg = msg;
        };
        ~LoadError() = default;

        const char *what() const throw() {
            return this->_msg.c_str();
        }

    protected:
    private:
        std::string _msg;
};

class WindowError : std::exception {
    public:
        WindowError(std::string msg) {
            this->_msg = msg;
        };
        ~WindowError() = default;

        const char *what() const throw() {
            return this->_msg.c_str();
        }

    protected:
    private:
        std::string _msg;
};

class DestroyError : std::exception {
    public:
        DestroyError(std::string msg) {
            this->_msg = msg;
        };
        ~DestroyError() = default;

        const char *what() const throw() {
            return this->_msg.c_str();
        }

    protected:
    private:
        std::string _msg;
};

#endif /* !ERROR_HPP_ */
