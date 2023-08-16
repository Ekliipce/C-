#include "dnl.hh"

std::vector<size_t> vect_size(const std::vector<std::string>& req)
{
    std::vector<size_t> v(req.size(), 0);
    std::transform(req.begin(), req.end(), v.begin(),
                   [=](std::string str) { return str.length(); });

    return v;
}

size_t min_elt_length(const std::vector<std::string>& req)
{
    std::vector<size_t> v = vect_size(req);
    return *std::min_element(v.begin(), v.end());
}

size_t max_elt_length(const std::vector<std::string>& req)
{
    std::vector<size_t> v = vect_size(req);
    return *std::max_element(v.begin(), v.end());
}

size_t sum_elt_length(const std::vector<std::string>& req)
{
    std::vector<size_t> v = vect_size(req);
    return std::accumulate(v.begin(), v.end(), 0);
}

size_t count_elt(const std::vector<std::string>& req, const std::string& elt)
{
    return std::count(req.begin(), req.end(), elt);
}

size_t count_duplicate(const std::vector<std::string>& req)
{
    std::vector<std::string> v(req);
    std::sort(v.begin(), v.end());
    auto it = std::unique(v.begin(), v.end());
    v.erase(it, v.end());

    return req.size() - v.size();
}
