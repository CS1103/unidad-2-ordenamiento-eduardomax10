#ifndef PROJECT2_MERGE_H
#define PROJECT2_MERGE_H

#include "Sort.h"

template<typename T>
void pop_front(std::vector<T> &v)
{
    if (v.size() > 0) {
        v.erase(v.begin());
    }
}

template <class T>
class Merge : public Sort<T>
{
private:
    std::vector<T> data_list;

public:
    Merge() : Sort<T>() {};
    explicit Merge(std::vector<T>* data_list_ptr) : Sort<T>(data_list_ptr)
    {
        data_list = *data_list_ptr;
    };

    std::vector<T> sort_data()
    {
        // Check if there is only one value in the data array
        if (data_list.size() == 1)
            return data_list;

        // Split data
        std::size_t const half_size = data_list.size() / 2;
        std::vector<T> data_lo(data_list.begin(), data_list.begin() + half_size);
        std::vector<T> data_hi(data_list.begin() + half_size, data_list.end());

        // Sort by merge
        Merge merge_lo(&data_lo);
        Merge merge_hi(&data_hi);
        data_lo = merge_lo.sort_data();
        data_hi = merge_hi.sort_data();

        return merge(data_lo, data_hi);
    }
    std::vector<T> merge(std::vector<T> data1, std::vector<T> data2)
    {
        std::vector<T> data3;
        while((!data1.empty()) and (!data2.empty()))
        {
            if (data1.front() > data2.front())
            {
                data3.push_back(data2.front());
                pop_front(data2);
            }
            else
            {
                data3.push_back(data1.front());
                pop_front(data1);
            }
        }

        while(!data1.empty())
        {
            data3.push_back(data1.front());
            pop_front(data1);
        }
        while(!data2.empty())
        {
            data3.push_back(data2.front());
            pop_front(data2);
        }
        return data3;
    }

};


#endif //PROJECT2_MERGE_H
