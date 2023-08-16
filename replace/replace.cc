#include "replace.hh"

#include <fstream>
#include <iostream>
#include <string>

void replace(const std::string& input_filename,
             const std::string& output_filename, const std::string& src_token,
             const std::string& dst_token)
{
    std::ofstream file_out;
    std::ifstream file_in;
    std::string lign;

    file_in.open(input_filename);
    if (!file_in.is_open())
    {
        std::cerr << "Cannot open input file" << '\n';
        return;
    }

    file_out.open(output_filename);
    if (!file_out.is_open())
    {
        std::cerr << "Cannot write output file" << '\n';
        return;
    }

    while (std::getline(file_in, lign))
    {
        size_t pos = 0;

        while ((pos = lign.find(src_token, pos)) != std::string::npos)
        {
            lign.replace(pos, src_token.length(), dst_token);
            pos += dst_token.length();
        }

        file_out << lign << '\n';
    }

    file_in.close();
    file_out.close();
}
