#include "Rotor.hpp"
#include <stdlib.h>

Rotor::Rotor(std::vector<int> configuration) : num_shifts(0)
{
    Rotor::set_up(configuration);
}

void Rotor::translate_forwards(int& input_char)
{
    int index = (input_char+num_shifts)%ALPHABET_LENGTH;
    int encoding = translation[index][1]-translation[index][0];

    input_char = (ALPHABET_LENGTH + input_char + encoding)%ALPHABET_LENGTH;
}

void Rotor::translate_backwards(int& input_char)
{

    int index = 0;
    while (translation [index][1] != (input_char+num_shifts)%ALPHABET_LENGTH)
    {
        index++;
    }
    int encoding = translation[index][0]-translation[index][1];

    input_char = (ALPHABET_LENGTH + input_char + encoding)%ALPHABET_LENGTH;
}

void Rotor::set_up(std::vector<int> configuration)
{
    int i = 0;
    std::vector<int>::iterator it;

    for(it = configuration.begin() ; i < ALPHABET_LENGTH; ++it, ++i)
    {
        translation[i][0] = i;
        translation[i][1] = (*it);
    }
}

void Rotor::shift()
{
    ++num_shifts;
    if (num_shifts == ALPHABET_LENGTH)
    {
        num_shifts = 0;
    }
}

int Rotor::get_num_shifts()
{
  return num_shifts;
}
