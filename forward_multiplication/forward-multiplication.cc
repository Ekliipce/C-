#include "forward-multiplication.hh"

lambda_type create_lambda()
{
    return [](int lhs) { return [lhs](int rhs) -> int { return lhs * rhs; }; };
}
