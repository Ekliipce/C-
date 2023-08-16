#include "player.hh"

#include "invalid-argument.hh"

Player::Player(const std::string& name, unsigned int age)
{
    if (name.empty())
        throw InvalidArgumentException("Name can't be empty.");
    else
        name_ = name;

    if (age > 150)
        throw InvalidArgumentException("Sorry gramp, too old to play.");
    else
        age_ = age;
}
