#include "closer-to.hh"

CloserTo::CloserTo(int i)
    : i_(i)
{}

int my_abs(int a)
{
    return (a < 0) ? -a : a;
}

bool CloserTo::operator()(const int& a, const int& b) const
{
    if (my_abs(this->i_ - a) != my_abs(this->i_ - b))
        return my_abs(this->i_ - a) < my_abs(this->i_ - b);
    else
        return a < b;
}
