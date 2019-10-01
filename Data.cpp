#include "Data.h"

Data::Data(std::string year, std::string race, std::string sex, std::string av_life, std::string age) :
    year{year}, race{race}, sex{sex}, av_life_expectancy{av_life}, age_adjusted_death_rate{age}
{}

void Data::print()
{
    std::cout << "year: " << year << ", ";
    std::cout << "race: " << race << ", ";
    std::cout << "sex: " << sex  << ", ";
    std::cout << "av life expectancy: " << av_life_expectancy << ", ";
    std::cout << "age adjusted death rate: " << age_adjusted_death_rate << std::endl;
}

int Data::get_year()
{
    return stoi(year);
}

int Data::get_age_adr()
{
    return stoi(age_adjusted_death_rate);
}
