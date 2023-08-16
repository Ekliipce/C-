#include "regiment.hh"

#include <iostream>
#include <string>

#include "soldier.hh"
Regiment::Regiment()
    : soldiers_({})
{}

Regiment::Regiment(std::vector<Soldier*> soldiers)
    : soldiers_(soldiers)
{}

void Regiment::join_by(Regiment& r)
{
    for (auto soldier : r.get_soldiers())
        this->soldiers_.push_back(soldier);
    r.get_soldiers().clear();
}

size_t Regiment::count() const
{
    return soldiers_.size();
}

std::vector<Soldier*>& Regiment::get_soldiers()
{
    return this->soldiers_;
}

void Regiment::add_soldier(Soldier* s)
{
    this->soldiers_.push_back(s);
}

void Regiment::print_state() const
{
    for (auto soldier : this->soldiers_)
        soldier->print_state();
}

void Regiment::scream() const
{
    for (auto soldier : this->soldiers_)
        soldier->scream();
}
