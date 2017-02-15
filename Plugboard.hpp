#ifndef PLUGBOARD_HPP
#define  PLUGBOARD_HPP

#include "Alphabet_Shifter.hpp"
#include <vector>

class Plugboard : public Alphabet_Shifter
{

public:
    Plugboard(std::vector<int> configuration);
    void translate(int& ind);

private:
    int translation[ALPHABET_LENGTH][2];
    void set_up(std::vector<int> configuration);

};
#endif
