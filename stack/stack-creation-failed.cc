#include "stack-creation-failed.hh"

const char* StackCreationFailed::what() const noexcept
{
    return this->err_.c_str();
}
