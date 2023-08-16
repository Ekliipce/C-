#pragma once

#include <exception>
#include <string>

class StackMaxSize : public std::exception
{
public:
    StackMaxSize(const std::string& err)
        : err_(err)
    {}

    const char* what() const noexcept;

private:
    const std::string err_;
};
