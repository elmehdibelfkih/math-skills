#include "../include/mathSkills.hpp"

Data::Data(const std::string &FileName)
{
    std::ifstream file(FileName);
    if (file.is_open())
    {
        try
        {
            this->loadData(file);
        }
        catch (const std::exception &e)
        {
            std::cerr << e.what() << '\n';
            file.close();
            std::exit(1);
        }

        file.close();
        this->computeStatistics();
    }
    else
    {
        std::cerr << "Failed to open file!\n";
        std::exit(1);
    }
}

Data::~Data()
{
    this->_data.clear();
}

void Data::loadData(std::ifstream &File)
{
    std::string line;

    while (std::getline(File, line))
    {
        char *end;
        this->_data.push_back(std::strtod(line.c_str(), &end));
        if (*end) {
            throw InvalidInputException();
        }
    }
}

void Data::computeStatistics()
{
    for (const auto &num : this->_data)
    {
        std::cout << num << std::endl;
    }
}

int Data::getAverage() const
{
    return this->_average;
}

int Data::getMedian() const
{
    return this->_median;
}

int Data::getVariance() const
{
    return this->_variance;
}

int Data::getStandardDeviation() const
{
    return this->_standardDeviation;
}

Data &Data::get_instance(const std::string &FileName)
{
    static Data instance = Data(FileName);
    return instance;
}

const char *Data::InvalidInputException::what() const throw()
{
    return "invalid data int the file";
}