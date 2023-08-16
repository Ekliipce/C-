#pragma once

constexpr unsigned long long factorial(unsigned int n)
{
    return n > 0 ? n * factorial(n - 1) : 1;
}
