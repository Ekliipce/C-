#pragma once

#include <exception>
#include <string>

class StackEmpty : public std::exception
{
public:
    StackEmpty(const std::string& err)
        : err_(err)
    {}

    const char* what() const noexcept;

private:
    const std::string err_;
};
