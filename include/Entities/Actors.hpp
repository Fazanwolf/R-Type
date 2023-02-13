/*
** EPITECH PROJECT, 2023
** B-CPP-500-RUN-5-2-rtype-lucas.miranville
** File description:
** Actors
*/

#ifndef ACTORS_HPP_
#define ACTORS_HPP_

class Actors : public Entity
{
    public:
        Actors();
        ~Actors();
        std::string getTag() {return this->tag}
        std::string getName()
        int getID();

    protected:
    private:
};

#endif /* !ACTORS_HPP_ */
