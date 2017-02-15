#include "Reflector.hpp"

Reflector::Reflector(int offset) : offset(offset)
{}

void Reflector::translate(int& input_char)
{
    input_char = (input_char+offset)%ALPHABET_LENGTH;
}
