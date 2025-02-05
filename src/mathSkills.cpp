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
    char *end;

    while (std::getline(File, line))
    {
        auto tmp = std::strtod(line.c_str(), &end);
        if (tmp != 0)
        {
            this->_data.push_back(tmp);
        }
        if (*end)
        {
            throw InvalidInputException();
        }
    }
    this->_data.shrink_to_fit();
    std::sort(this->_data.begin(), this->_data.end());
}

void Data::computeStatistics()
{
    int len = this->_data.size();
    double tmp = 0;
    double Average = 0;
    double squaredDifferences = 0;
    double variance = 0;
    if (len % 2 != 0)
    {
        this->_median = std::round(this->_data[len / 2]);
    }
    else
    {
        this->_median = std::floor((this->_data[len / 2] + this->_data[(len / 2) + 1]) / 2);
    }
    for (const auto &num : this->_data)
    {
        tmp += num;
    }
    Average = tmp / len;
    this->_average = std::round(Average);
    for (const auto &num : this->_data)
    {
        squaredDifferences += std::pow(num - Average, 2);
    }
    variance = squaredDifferences / len;
    this->_variance = std::round(variance);
    this->_standardDeviation = std::round(std::sqrt(variance));
}

long Data::getAverage() const
{
    return this->_average;
}

long Data::getMedian() const
{
    return this->_median;
}

long Data::getVariance() const
{
    return this->_variance;
}

long Data::getStandardDeviation() const
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