#ifndef ENIGMA_HPP
#define  ENIGMA_HPP

#ifndef REFLECTOR_OFFSET
#define REFLECTOR_OFFSET 13
#endif

#ifndef ALPHABET_LENGTH
#define ALPHABET_LENGTH 26
#endif

#include "Helpers.hpp"
#include "Reflector.cpp"
#include "Plugboard.cpp"
#include "Rotor.cpp"

class Enigma {

public:
    Enigma(std::string* rotor_config, int num_rotors,
            std::string plugboard_config);
    void translate(int& input_char);


private:
    Reflector* reflector;
    Plugboard* plugboard;
    std::vector<Rotor*> rotors;
    int num_rotors;
    void set_rotors(std::string* rotor_config, int num_rotors);
    void set_plugboard(std::string plugboard_config);
    void set_reflector();
    void shift_rotors();
};

#endif
