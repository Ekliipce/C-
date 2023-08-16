#include "vehicle.hh"

#include <iostream>

Vehicle::Vehicle(const std::string& model, int fuel)
    : model_(model)
    , engine_(fuel)
{}

bool Vehicle::start()
{
    return this->engine_.start();
}

void Vehicle::stop()
{
    this->engine_.stop();
}

void Vehicle::cruise(int fuel)
{
    this->engine_.use(fuel);
}

void Vehicle::fill(int fuel)
{
    this->engine_.fill(fuel);
}
