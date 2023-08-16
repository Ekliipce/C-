#pragma once
#include "dico.hh"

template <typename Iterator>
Dico::Dico(Iterator begin, Iterator end)
    : dico_(std::set<std::string>(begin, end))
{}
