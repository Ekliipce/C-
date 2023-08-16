#include "parse-csv.hh"

#include <fstream>

int is_file_correct(std::vector<std::vector<std::string>> v)
{
    size_t ref = v.at(0).size();
    for (size_t i = 1; i < v.size(); i++)
    {
        if (v.at(i).size() != ref)
            return i;
    }

    return 0;
}

std::vector<std::vector<std::string>> parse_csv(const std::string& file_name)
{
    std::ifstream file;
    std::vector<std::vector<std::string>> vect;
    std::string line;
    int nb_col = 0;

    file.open(file_name);
    if (!file.is_open())
        throw std::ios_base::failure("Error opening file");

    while (getline(file, line))
    {
        std::vector<std::string> line_v;
        std::string str;

        for (size_t i = 0; i < line.length(); i++)
        {
            if (line[i] == ',')
            {
                line_v.push_back(str);
                str.clear();
                nb_col++;

                continue;
            }
            str.push_back(line[i]);
        }

        line_v.push_back(str);
        vect.push_back(line_v);
    }

    int err = is_file_correct(vect);
    if (!err == 0)
        throw std::ios_base::failure("Non consistent number of columns at line "
                                     + std::to_string(err + 1));

    return vect;
}
