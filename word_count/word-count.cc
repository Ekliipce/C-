#include <fstream>
#include <iostream>

ssize_t word_count(const std::string& filename)
{
    ssize_t count = 0;
    std::ifstream file;
    std::string token;

    file.open(filename);
    if (!file.is_open())
        return -1;

    while (file >> token)
        count++;

    file.close();

    return count;
}
