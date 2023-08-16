#pragma once
#include <exception>
#include <string>

class StackCreationFailed : public std::exception
{
public:
    StackCreationFailed(const std::string& err)
        : err_(err)
    {}

    const char* what() const noexcept;

private:
    const std::string err_;
};
