#pragma once

#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>
#include <cmath>

class Data
{
private:
    std::vector<float> _data;
    long _average;
    long _median;
    long _variance;
    long _standardDeviation;

    explicit Data(const std::string &FileName);
    void loadData(std::ifstream &File);
    void computeStatistics();

public:
    static Data &get_instance(const std::string &FileName);

    ~Data();
    Data(const Data &) = delete;
    Data &operator=(const Data &) = delete;

    long getAverage() const;
    long getMedian() const;
    long getVariance() const;
    long getStandardDeviation() const;
    class InvalidInputException : public std::exception
    {
    public:
        const char * what() const throw();
    };
};
