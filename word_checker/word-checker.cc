#include "word-checker.hh"

#include <iostream>
// #include <string>
#include <fstream>

WordChecker::WordChecker(std::string path)
    : path_(path)
{
    std::string line;
    std::fstream file;

    file.open(path);

    while (getline(file, line))
    {
        if (line.length() == 1)
        {
            dico_pairs_.insert(line);
            // std::cout << "letter : " << line << '\n';
        }
        else
        {
            for (size_t i = 1; i < line.length(); i++)
            {
                std::string pairs(line, i - 1, 2);
                dico_pairs_.insert(pairs);
                // std::cout << pairs << '\n';
            }
        }
    }
}

bool WordChecker::operator()(std::string word)
{
    size_t len = word.length();
    // std::cout << len << '\n';
    if (len == 1)
        return (this->dico_pairs_.find(word) != this->dico_pairs_.end())
            ? true
            : false;

    for (size_t i = 0; i < len - 1; i++)
    {
        std::string pairs(word, i, 2);
        // std::cout << pairs << '\n';
        if (this->dico_pairs_.find(pairs) == this->dico_pairs_.end())
            return false;
    }

    return true;
}
