#include "Plugboard.hpp"


Plugboard::Plugboard(std::vector<int> configuration)
{
    Plugboard::set_up(configuration);
}

void Plugboard::translate(int& input_char)
{
    input_char = translation[input_char][1];
}

void Plugboard::set_up(std::vector<int> configuration)
{
    for (size_t i = 0; i < 26; i++)
    {
        translation[i][0] = translation[i][1] = i;
    }

    std::vector<int>::iterator it;
    for(it = configuration.begin() ; it != configuration.end(); ++it)
    {
        int temp = (*it);
        translation[temp][1]  = *(++it);
        translation[(*it)][1] = temp;
    }
}
