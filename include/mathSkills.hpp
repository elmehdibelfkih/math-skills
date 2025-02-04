#pragma once

#include <iostream>
#include <vector>
#include <fstream>

class Data
{
private:
    std::vector<double> _data;
    int _average;
    int _median;
    int _variance;
    int _standardDeviation;

    explicit Data(const std::string &FileName);
    void loadData(std::ifstream &File);
    void computeStatistics();

public:
    static Data &get_instance(const std::string &FileName);

    ~Data();
    Data(const Data &) = delete;
    Data &operator=(const Data &) = delete;

    int getAverage() const;
    int getMedian() const;
    int getVariance() const;
    int getStandardDeviation() const;
    class InvalidInputException : public std::exception
    {
    public:
        const char * what() const throw();
    };
};
