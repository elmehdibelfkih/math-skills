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
    std::cout << "Average: " << population.getAverage() << std::endl;
    std::cout << "Median: " << population.getMedian() << std::endl;
    std::cout << "Variance: " << population.getVariance() << std::endl;
    std::cout << "Standard Deviation: " << population.getStandardDeviation() << std::endl;
    return 0;
}