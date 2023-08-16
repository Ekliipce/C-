#pragma once

#include <set>
#include <string>

unsigned levenshtein(const std::string& s1, const std::string& s2);

class Dico
{
public:
    Dico() = default;

    Dico(const std::set<std::string>& dico);

    template <typename Iterator>
    Dico(Iterator begin, Iterator end);

    void dump_dico() const;
    bool add_word(const std::string& s);
    bool remove_word(const std::string& s);

    std::set<std::string> find_prefix(const std::string& req) const;
    std::set<std::string> find_suffix(const std::string& req) const;
    std::set<std::string> contains(const std::string& req) const;
    std::set<std::string> find_similar(const std::string& req,
                                       unsigned size) const;

private:
    std::set<std::string> dico_;
};

#include "dico.hxx"
