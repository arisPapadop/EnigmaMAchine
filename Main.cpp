// skeleton C++ file, you will need to edit this and other files to implement your enigma machine
#include <stdexcept>
#include <iostream>
#include <fstream>
#include <algorithm>

#include "Enigma.cpp"


using namespace std;

int main(int argc, char **argv)
{

    if (argc == 1)
    {
      std::cerr << "Error: no configuration file" << std::endl;
      exit(-1);
    }
    
    //All but the last arguments are rotor configurations.
    int num_rotors = argc-2;
    string rotor_config[num_rotors];
    for (int i = 0; i < num_rotors; i++)
    {
      ifstream rotor_input(argv[i+1]);
      if(rotor_input)
      {
          getline(rotor_input, rotor_config[i]);
      }
      else
      {
        std::cerr << "Error: non-existent file" << std::endl;
        exit(-1);
      }
    }

    //The last argument is the plugboard configuration.
    string plugboard_config;
    ifstream rotor_input(argv[argc-1]);
    if(rotor_input)
    {
      getline(rotor_input, plugboard_config);
    }
    else
    {
      std::cerr << "Error: non-existent file" << std::endl;
      exit(-1);
    }

    Enigma *machine = new Enigma(rotor_config, num_rotors, plugboard_config);

    char to_encode;
    while(cin >> ws >> to_encode)
    {
        int input = char_to_int(to_encode);
        machine->translate(input);
        cout << int_to_char(input);
    }
    std::cout << std::endl;
}
