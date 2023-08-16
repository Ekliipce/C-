#include "engine.hh"

#include <iostream>

Engine::Engine(int fuel)
    : fuel_(fuel)
{}

bool Engine::start()
{
    if (this->fuel_ <= 0)
        return false;

    this->fuel_--;

    std::cout << "Engine starts with " << this->fuel_ << " units of fuel"
              << '\n';
    return true;
}

void Engine::use(int consumed)
{
    if (consumed > this->fuel_)
        consumed = this->fuel_;

    this->fuel_ -= consumed;
    std::cout << "Engine uses " << consumed << " fuel units" << '\n';
}

void Engine::stop() const
{
    std::cout << "Stop Engine" << '\n';
}

void Engine::fill(int fuel)
{
    this->fuel_ += fuel;
    std::cout << "Engine now has " << this->fuel_ << " fuel units" << '\n';
}
