#pragma once

#include <cmath>
#include <iostream>

template <typename Iterator, typename Function>
void my_foreach(Iterator begin, Iterator end, Function f)
{
    for (; begin != end; begin++)
        f(*begin);
}
