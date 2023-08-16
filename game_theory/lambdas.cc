#include "lambdas.hh"

#include <iostream>

bool is_cheated(iterator_type it)
{
    return (*it == -1 || *it == 0);
}

strategy_type cooperator()
{
    return [](iterator_type begin, iterator_type end) -> bool {
        (void)begin;
        (void)end;
        return true;
    };
}

strategy_type cheater()
{
    return [](iterator_type begin, iterator_type end) -> bool {
        (void)begin;
        (void)end;
        return false;
    };
}

strategy_type copycat()
{
    return [](iterator_type begin, iterator_type end) -> bool {
        if (begin == end)
            return true;
        else
        {
            if (is_cheated(end - 1))
                return false;
            else
                return true;
        }
    };
}

strategy_type grudger()
{
    return [](iterator_type begin, iterator_type end) -> bool {
        for (iterator_type curr = begin; curr != end; curr++)
        {
            if (is_cheated(curr))
                return false;
        }

        return true;
    };
}

strategy_type detective()
{
    return [](iterator_type begin, iterator_type end) -> bool {
        if (begin == end || begin == end - 2 || begin == end - 3)
            return true;
        else if (begin == end - 1)
            return false;

        for (iterator_type curr = begin; curr != begin + 4; curr++)
        {
            if (is_cheated(curr))
                return copycat()(begin, end);
        }

        return cheater()(begin, end);
    };
}

strategy_type copykitten()
{
    return [](iterator_type begin, iterator_type end) -> bool {
        if (begin == end || begin == end - 1)
            return true;
        else
        {
            if (is_cheated(end - 1) && is_cheated(end - 2))
                return false;
            return true;
        }
    };
}
