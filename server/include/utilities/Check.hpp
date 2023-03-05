#ifndef UTILITIES_CHECK_HPP
#define UTILITIES_CHECK_HPP

#include <iostream>
#include <regex>

namespace utilities {

    class Check {
    public:
        /**
         * @brief Check if the string is a valid ip
         * @param ip The string to check
         * @return bool
         */
        static bool isIp(const std::string &ip);
        /**
         * @brief Check if the string is a valid port
         * @param port The string to check
         * @return bool
         */
        static bool isPort(const std::string &port);
        /**
         * @brief Check if the target is the flag or the alias
         * @param target The target string to compare with the flag and the alias
         * @param flag The flag string
         * @param alias The alias string
         * @return bool
         */
        static bool isAlias(const std::string &target, const std::string &flag, const std::string &alias);
    private:
        static const std::regex _portPattern;
        static const std::regex _ipPattern;
    };

}

#endif //UTILITIES_CHECK_HPP