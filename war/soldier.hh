#pragma once

#include <iostream>
#include <string>

class Soldier
{
public:
    Soldier();
    Soldier(int health, int damage_, std::string);

    void attack(Soldier& s);
    void print_state() const;
    void scream() const;

protected:
    int health_;
    int damage_;
    std::string scream_;
};
