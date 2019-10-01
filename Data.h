#ifndef PROJECT2_DATA_H
#define PROJECT2_DATA_H

#include <string>
#include <iostream>

class Data
{
private:
    std::string year;
    std::string race;
    std::string sex;
    std::string av_life_expectancy;
    std::string age_adjusted_death_rate;

public:
    Data(std::string year, std::string race, std::string sex, std::string av_life, std::string age);
    void print();
    int get_year();
    int get_age_adr();
};


#endif //PROJECT2_DATA_H
