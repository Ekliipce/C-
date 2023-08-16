#include "dico.hh"

#include <algorithm>
#include <iostream>

Dico::Dico(const std::set<std::string>& dico)
    : dico_(dico)
{}

void Dico::dump_dico() const
{
    for (auto elm : dico_)
        std::cout << elm << '\n';
}

bool Dico::add_word(const std::string& s)
{
    if (this->dico_.find(s) != this->dico_.end())
        return false;

    this->dico_.insert(s);
    return true;
}

bool Dico::remove_word(const std::string& s)
{
    return this->dico_.erase(s) != 0;
}

std::set<std::string> Dico::find_prefix(const std::string& req) const
{
    std::set<std::string> set_prefix;
    size_t len = req.length();

    for (auto elm : this->dico_)
    {
        std::string pref = elm.substr(0, len);
        if (pref.compare(req) == 0)
            set_prefix.insert(elm);
    }

    return set_prefix;
}

std::set<std::string> Dico::find_suffix(const std::string& req) const
{
    std::set<std::string> set_suffix;
    int len = req.length();

    for (auto elm : this->dico_)
    {
        int pos = elm.length() - len;
        if (pos < 0)
            continue;

        std::string suf = elm.substr(pos, len);
        if (suf.compare(req) == 0)
            set_suffix.insert(elm);
    }

    return set_suffix;
}

std::set<std::string> Dico::contains(const std::string& req) const
{
    std::set<std::string> set_contains;

    for (auto elm : this->dico_)
    {
        if (elm.find(req) != std::string::npos)
            set_contains.insert(elm);
    }

    return set_contains;
}

static int min(int a, int b, int c)
{
    int min;
    if (a <= b && a <= c)
        min = a;
    else if (b <= a && b <= c)
        min = b;
    else
        min = c;

    return min;
}

unsigned levenshtein(const std::string& s1, const std::string& s2)
{
    const size_t len = s1.length() + 1;
    const size_t len2 = s2.length() + 1;

    std::vector<std::vector<unsigned>> arr(len2 + 1,
                                           std::vector<unsigned>(len + 1));
    arr[0][0] = 0;

    for (size_t i = 1; i <= len2; i++)
        arr[i][0] = arr[i - 1][0] + 1;
    for (size_t j = 1; j <= len; j++)
        arr[0][j] = arr[0][j - 1] + 1;

    for (size_t i = 1; i <= len2; i++)
    {
        for (size_t j = 1; j <= len; j++)
        {
            int add = 1;
            if (s1[j - 1] == s2[i - 1])
                add = 0;

            int a = arr[i - 1][j];
            int b = arr[i][j - 1];
            int c = arr[i - 1][j - 1];

            arr[i][j] = min(a + 1, b + 1, c + add);
        }
    }

    return arr[len2][len];
}

std::set<std::string> Dico::find_similar(const std::string& req,
                                         unsigned size) const
{
    std::set<std::string> set_similar;

    for (auto elm : this->dico_)
    {
        if (levenshtein(elm, req) <= size)
            set_similar.insert(elm);
    }

    return set_similar;
}
