#include "vector.hh"

#include "iostream"
#include "ostream"

Vector& Vector::operator+=(const Vector& rhs)
{
    this->x += rhs.x;
    this->y += rhs.y;
    return *this;
}

Vector& Vector::operator-=(const Vector& rhs)
{
    this->x -= rhs.x;
    this->y -= rhs.y;
    return *this;
}

Vector& Vector::operator*=(int scalar)
{
    this->x *= scalar;
    this->y *= scalar;
    return *this;
}

Vector operator+(const Vector& lhs, const Vector& rhs)
{
    int new_x = lhs.x + rhs.x;
    int new_y = lhs.y + rhs.y;
    return Vector(new_x, new_y);
}

Vector operator-(const Vector& lhs, const Vector& rhs)
{
    int new_x = lhs.x - rhs.x;
    int new_y = lhs.y - rhs.y;
    return Vector(new_x, new_y);
}

Vector operator*(const Vector& lhs, int scalar)
{
    int new_x = lhs.x * scalar;
    int new_y = lhs.y * scalar;
    return Vector(new_x, new_y);
}

Vector operator*(int scalar, const Vector& rhs)
{
    int new_x = rhs.x * scalar;
    int new_y = rhs.y * scalar;
    return Vector(new_x, new_y);
}

int operator*(const Vector& lhs, const Vector& rhs)
{
    int res = lhs.x * rhs.x + lhs.y * rhs.y;
    return res;
}

std::ostream& operator<<(std::ostream& os, const Vector& vect)
{
    return os << "{" << vect.x << "," << vect.y << "}";
}
