#ifndef REFLECTOR_HPP
#define  REFLECTOR_HPP

#include "Alphabet_Shifter.hpp"

class Reflector : public Alphabet_Shifter {

public:
    Reflector(int offset);
    void translate(int& ind);

private:
    const int offset;

};

#endif
