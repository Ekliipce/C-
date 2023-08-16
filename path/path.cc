#include "path.hh"

Path& Path::join(const std::string& tail, bool is_file)
{
    if (this->final_)
        return *this;

    this->path_.push_back(tail);
    this->final_ = is_file;

    return *this;
}
