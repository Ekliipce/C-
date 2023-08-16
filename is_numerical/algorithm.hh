#pragma once

#include "enable-if.hh"
#include "is-numerical.hh"

template <typename T>
enable_if<is_numerical<T>::value, T>::type algorithm(T t)
{
    typename enable_if<is_numerical<T>::value, T>::type enable = t;

    return enable;
}
