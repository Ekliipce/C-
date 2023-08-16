#include <fstream>
#include <iostream>

void stdin_to_file()
{
    std::ofstream file;
    std::string token;

    file.open("file.out");
    if (!file.is_open())
        return;

    while (std::cin >> token)
        file << token << "\n";

    file.close();
}
