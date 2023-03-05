/*
** EPITECH PROJECT, 2023
** R-Type-client
** File description:
** String
*/

#include <iostream>
#include <list>
#include <vector>

#ifndef STRING_HPP_
#define STRING_HPP_
class StringUtils {
public:
    static std::list<std::string> split_str(size_t pos, std::string& s, std::string delimiter)
    {
        std::string token;
        std::list<std::string> parsed;
        while ((pos = s.find(delimiter)) != std::string::npos) {
            token = s.substr(0, pos);
            parsed.insert(parsed.cend(), token);
            s.erase(0, pos + delimiter.length());
        }
        return parsed;
    }

    static std::vector<std::string> split(std::string &s, char delim)
    {
        std::vector<std::string> elems;
        std::stringstream ss(s);
        std::string item;

        while (std::getline(ss, item, delim)) elems.push_back(item);
        return elems;
    }
};

#endif /* !STRING_HPP_ */
