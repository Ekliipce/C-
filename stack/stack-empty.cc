
#include "stack-empty.hh"

const char* StackEmpty::what() const noexcept
{
    return this->err_.c_str();
}
