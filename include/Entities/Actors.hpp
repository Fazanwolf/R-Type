/*
** EPITECH PROJECT, 2023
** B-CPP-500-RUN-5-2-rtype-lucas.miranville
** File description:
** Actors
*/

#ifndef ACTORS_HPP_
#define ACTORS_HPP_

/**
 * @brief This class is the base class for all the actors in the game 
 */
class Actors : public Entity
{
    public:
        /**
        * @brief This function is the constructor of the Actors class
        */
        Actors();
        /**
        * @brief This function is the destructor of the Actors class
        */
        ~Actors();
        /**
        * @brief This function gets the tag of the actor.
        * @return The tag of the actor.
        */
        std::string getTag() {return this->tag}
        /**
        * @brief This function get the name of the actor.
        * @return The name of the actor.
        */
        std::string getName()
        /**
        * @brief This function get the id of the actor.
        * @return The id of the actor.
        */
        int getID();

    protected:
    private:
};

#endif /* !ACTORS_HPP_ */
