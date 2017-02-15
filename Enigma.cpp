#include "Enigma.hpp"

Enigma::Enigma(std::string* rotor_config, int num_rotors,
        std::string plugboard_config)
        : num_rotors(num_rotors)
{
    set_reflector();
    set_plugboard(plugboard_config);
    set_rotors(rotor_config, num_rotors);

}

void Enigma::translate(int& input_char)
{

    plugboard->translate(input_char);

    for (int i = 0; i < num_rotors; i++)
    {
        rotors[i]->translate_forwards(input_char);
    }

    reflector->translate(input_char);

    for (int i = num_rotors-1; i >= 0; i--)
    {
        rotors[i]->translate_backwards(input_char);
    }

    plugboard->translate(input_char);

    shift_rotors();
}

void Enigma::set_rotors(std::string* rotor_config, int num_rotors)
{
    for (int i = 0; i < num_rotors; i++, rotor_config++)
    {
        rotors.push_back(new Rotor(string_to_vector(*rotor_config)));
    }
}

void Enigma::set_plugboard(std::string plugboard_config)
{
    plugboard = new Plugboard(string_to_vector(plugboard_config));
}

void Enigma::set_reflector()
{
    reflector = new Reflector(REFLECTOR_OFFSET);
}

void Enigma::shift_rotors()
{
    if(num_rotors > 0)
    {
    rotors[0]->shift();
    }

    for(int i = 0; i < num_rotors-1; i++)
    {
        if ((rotors[i]->get_num_shifts())%ALPHABET_LENGTH == 0)
        {
            rotors[i+1]->shift();
        }
    }
}
