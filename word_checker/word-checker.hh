#pragma once

#include <iostream>
#include <set>
#include <string>

class WordChecker
{
public:
    WordChecker(std::string path);

    bool operator()(std::string path);

private:
    std::string path_;
    std::set<std::string> dico_letters_;
    std::set<std::string> dico_pairs_;
};