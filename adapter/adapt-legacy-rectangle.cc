#include "adapt-legacy-rectangle.hh"

#include <iostream>

AdaptLegacyRectangle::AdaptLegacyRectangle(LegacyRectangle& rect)
    : rect_(rect)
{}

AdaptLegacyRectangle::~AdaptLegacyRectangle()
{}

int my_abs(int x, int y)
{
    return (x - y >= 0) ? x - y : y - x;
}

void AdaptLegacyRectangle::print() const
{
    std::cout << "x: " << rect_.x1_get() << " y: " << rect_.y1_get() << '\n';
    std::cout << "height: " << my_abs(rect_.y2_get(), rect_.y1_get()) << '\n';
    std::cout << "width: " << my_abs(rect_.x2_get(), rect_.x1_get()) << '\n';
}

unsigned AdaptLegacyRectangle::area() const
{
    return this->rect_.compute_area();
}
