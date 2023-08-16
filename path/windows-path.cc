#include "windows-path.hh"

WindowsPath::WindowsPath(char drive)
    : drive_(drive)
{}

bool WindowsPath::check_name(const std::string& name)
{
    size_t found = -1;
    for (size_t i = 0; i < name.size(); i++)
    {
        found = name.find_first_of(":\"|?*", found + 1);
        if (found != std::string::npos)
            return false;
    }

    return true;
}

std::string WindowsPath::to_string() const
{
    std::string str;
    str.push_back(this->drive_);
    str.push_back(':');
    for (auto elm : this->path_)
        str.append("\\").append(elm);

    if (!this->final_)
        str.append("\\");

    return str;
}

Path& WindowsPath::join(const std::string& tail, bool is_file)
{
    if (this->final_)
        return *this;

    if (check_name(tail))
    {
        this->path_.push_back(tail);
        this->final_ = is_file;
    }

    return *this;
}
