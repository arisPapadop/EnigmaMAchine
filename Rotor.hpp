#ifndef ROTOR_HPP
#define  ROTOR_HPP

class Rotor
{

public:
    Rotor(std::vector<int> configuration);
    void translate_forwards (int& ind);
    void translate_backwards(int& ind);
    int get_num_shifts();  
    void shift();

private:
    int translation[ALPHABET_LENGTH][2];
    void set_up(std::vector<int> configuration);
    int num_shifts;

};
#endif
