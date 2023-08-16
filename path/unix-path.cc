#include "unix-path.hh"

std::string UnixPath::to_string() const
{
    std::string str;
    for (auto elm : this->path_)
        str.append("/").append(elm);

    if (!this->final_)
        str.append("/");

    return str;
}
