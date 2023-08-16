#pragma once

template <typename vector>
bool palindrome(vector vec)
{
    auto begin = vec.begin();
    auto end = vec.end();

    while (begin < end)
    {
        if (*begin != *(end - 1))
            return false;

        begin++;
        end--;
    }

    return true;
}
