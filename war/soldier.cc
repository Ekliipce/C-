#include "soldier.hh"

#include <iostream>
#include <string>

Soldier::Soldier()
    : health_(15)
    , damage_(3)
    , scream_("No pity for losers!\n")
{}

Soldier::Soldier(int health, int damage, std::string scream)
    : health_(health)
    , damage_(damage)
    , scream_(scream.append("\n"))
{}

void Soldier::attack(Soldier& s)
{
    s.health_ -= this->damage_;
}

void Soldier::print_state() const
{
    std::cout << "I have " << this->health_ << " health points.\n";
}

void Soldier::scream() const
{
    std::cout << this->scream_;
}
