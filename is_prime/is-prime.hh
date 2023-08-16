#pragma once

template <unsigned T>
constexpr bool is_prime()
{
    if (T == 1 || T == 0)
        return false;
    else
    {
        for (int i = 2; i * i <= T; i++)
        {
            if (T % i == 0)
                return false;
        }
    }

    return true;
}
