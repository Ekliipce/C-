#include "stack-max-size.hh"

const char* StackMaxSize::what() const noexcept
{
    return this->err_.c_str();
}
