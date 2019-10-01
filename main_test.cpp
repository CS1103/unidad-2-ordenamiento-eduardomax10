#include "main.h"

template <typename T>
bool check_if_is_sorted(std::vector<T> data_list)
{
    bool sorted = true;
    T pre_age = 0;
    for (auto &age_adr : data_list)
        if (age_adr >= pre_age)
            pre_age = age_adr;
        else
            sorted = false;
    return sorted;
}

SCENARIO("Sorting Library")
{
    // Path
    std::string path = "data.csv";

    // Read CSV file
    std::ifstream csv_file{path};
    std::vector<Data*> data_list;

    if(!csv_file.is_open())
        std::cout << "ERROR: Opening " << path << std::endl;

    while(csv_file.good())
    {
        std::string year;
        std::string race;
        std::string sex;
        std::string av_life_expectancy;
        std::string age_adjusted_death_rate;

        getline(csv_file, year, ',');
        getline(csv_file, race, ',');
        getline(csv_file, sex, ',');
        getline(csv_file, av_life_expectancy, ',');
        getline(csv_file, age_adjusted_death_rate, '\n');

        data_list.push_back(new Data(year, race, sex, av_life_expectancy, age_adjusted_death_rate));
    }
#ifdef DEBUG
    // Print Data
        std::cout "------------------------------------------" std::endl;
        std::cout << "Data: " << std::endl;
        std::cout "------------------------------------------" std::endl;
        for(auto &data : data_list)
        {
            std::cout << i << ": ";
            data->print();
            i++;
        }
#endif
    std::vector<int> age_adr_list;
    for(auto &data : data_list)
    {
        age_adr_list.push_back(data->get_age_adr());
    }
    GIVEN("Merge sort algorithm")
    {
        Merge<int> merge(&age_adr_list);
        WHEN("Applying")
        {
            std::vector<int> merge_sorted_data(merge.sort_data());
#ifdef DEBUG
            for(auto &age_adr : merge_sorted_data)
                std::cout << "Age adjusted death rate: " << age_adr << std::endl;
#endif
            THEN("Check results")
            {
                REQUIRE(check_if_is_sorted(merge_sorted_data));
            }
        }
    }
    GIVEN("Quick sort algorithm")
    {
        Quick<int> quick(&age_adr_list);
        WHEN("Applying")
        {
            std::vector<int> quick_sorted_data(quick.sort_data());
#ifdef DEBUG
            for(auto &age_adr : quick_sorted_data)
                std::cout << "Age adjusted death rate: " << age_adr << std::endl;
#endif
            THEN("Check results")
            {
                REQUIRE(check_if_is_sorted(quick_sorted_data));
            }
        }
    }
    GIVEN("Heap sort algorithm")
    {
        Heap<int> heap(&age_adr_list);
        WHEN("Applying")
        {
            std::vector<int> heap_sorted_data(heap.sort_data());
#ifdef DEBUG
            for(auto &age_adr : heap_sorted_data)
                std::cout << "Age adjusted death rate: " << age_adr << std::endl;
#endif
            THEN("Check results")
            {
                REQUIRE(check_if_is_sorted(heap_sorted_data));
            }
        }
    }
    GIVEN("Shell sort algorithm")
    {
        Shell<int> shell(&age_adr_list);
        WHEN("Applying")
        {
            std::vector<int> shell_sorted_data(shell.sort_data());

#ifdef DEBUG
            for(auto &age_adr : heap_sorted_data)
                std::cout << "Age adjusted death rate: " << age_adr << std::endl;
#endif

            THEN("Check results")
            {
                REQUIRE(check_if_is_sorted(shell_sorted_data));
            }
        }
    }
}