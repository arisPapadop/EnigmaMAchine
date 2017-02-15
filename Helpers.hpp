#include <string>
#include <sstream>
#include <vector>
#include <ctype.h>


int char_to_int(char c)
{
    if (isupper(c))
    {
        return c - 'A';
    }
    std::cerr << "Error: expecting capital letters only." << std::endl;
    exit(-1);
}

char int_to_char(int i)
{
    return i + 'A';
}

std::vector<int> string_to_vector (std::string configuration)
{
    std::vector<int> configuration_ints;
    std::stringstream stream(configuration);
    int n;

    while(stream >> n)
    {
        configuration_ints.push_back(n);
    }
    return configuration_ints;
}
