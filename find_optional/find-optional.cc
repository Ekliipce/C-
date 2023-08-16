#include "find-optional.hh"

#include <iostream>
#include <optional>

std::optional<std::size_t> find_optional(const std::vector<int>& vect,
                                         int value)
{
    for (size_t i = 0; i < vect.size(); i++)
    {
        if (vect[i] == value)
            return std::optional<std::size_t>{ i };
    }

    return std::nullopt;
}
