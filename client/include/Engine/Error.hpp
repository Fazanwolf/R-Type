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

/**
* @brief This class is the base class for all the Error
*/
class Error : std::exception {
    public:

        /**
        * @brief Constructor for class Error to set an error message
        *
        * @param msg message of the error
        */
        Error(std::string msg) {
            this->_msg = msg;
        };

        /**
        * @brief Destructor for class Error
        */
        ~Error() = default;

        /**
        * @brief Function to return an error message
        *
        * @return Return a error message in char *
        */
        const char *what() const throw() {
            return this->_msg.c_str();
        }

    protected:
    private:
        std::string _msg;
};

/**
* @brief This class is the base class for all the LoadError
*/
class LoadError : std::exception {
    public:

        /**
        * @brief Constructor for class LoadError to set an error message
        *
        * @param msg message of the error
        */
        LoadError(std::string msg) {
            this->_msg = msg;
        };

        /**
        * @brief Destructor for class LoadError
        */
        ~LoadError() = default;

        /**
        * @brief Function to return an error message
        */
        const char *what() const throw() {
            return this->_msg.c_str();
        }

    protected:
    private:
        std::string _msg;
};

/**
* @brief This class is the base class for all the WindowError
*/
class WindowError : std::exception {
    public:

        /**
        * @brief Constructor for class WindowError to set an error message
        *
        * @param msg message of the error
        */
        WindowError(std::string msg) {
            this->_msg = msg;
        };

        /**
        * @brief Destructor for class WindowError
        */
        ~WindowError() = default;

        /**
        * @brief Function to return an error message
        */
        const char *what() const throw() {
            return this->_msg.c_str();
        }

    protected:
    private:
        std::string _msg;
};

/**
* @brief This class is the base class for all the DestroyError
*/
class DestroyError : std::exception {
    public:

        /**
        * @brief Constructor for class DestroyError to set an error message
        *
        * @param msg message of the error
        */
        DestroyError(std::string msg) {
            this->_msg = msg;
        };

        /**
        * @brief Destructor for class DestroyError
        */
        ~DestroyError() = default;

        /**
        * @brief Function to return an error message
        */
        const char *what() const throw() {
            return this->_msg.c_str();
        }

    protected:
    private:
        std::string _msg;
};

#endif /* !ERROR_HPP_ */
