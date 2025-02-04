#include "../include/mathSkills.hpp"

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        std::cerr << "Error: Invalid number of arguments!" << std::endl
                  << "Usage: ./executable [file]" << std::endl;
        return 1;
    }
    Data &population = Data::get_instance((std::string)argv[1]);
    population.getAverage();
    return 0;
}