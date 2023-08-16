#include "motor-truck.hh"

#include <iostream>

#include "vehicle.hh"

MotorTruck::MotorTruck(const std::string& model, int fuel, size_t nb_tires)
    : Vehicle(model, fuel)
    , nb_tires_(nb_tires)
{}

void MotorTruck::change_tires() const
{
    std::cout << "Changing all " << this->nb_tires_ << " tires of the "
              << this->model_ << '\n';
}
