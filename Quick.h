#ifndef PROJECT2_QUICK_H
#define PROJECT2_QUICK_H

#include "Sort.h"

template <class T>
class Quick : public Sort<T>
{
private:
    std::vector<T> data_list;
public:
    Quick() : Sort<T>() {};
    explicit Quick(std::vector<T>* data_list_ptr) : Sort<T>(data_list_ptr)
    {
        data_list = *data_list_ptr;
    }
    int partition(std::vector<T> * arr, int low, int high)
    {
        int pivot = arr->at(high);
        int i = low-1;
        for (int j = low; j <= high -1; j++)
            if (arr->at(j) <= pivot)
            {
                i++;
                iter_swap(arr->begin() + i, arr->begin() + j);
            }
        iter_swap(arr->begin() + i + 1, arr->begin()+ high);
        return i+1;
    }
    void quick_sort(std::vector<T> * arr, int low, int high)
    {
        if (low < high)
        {
            int pivot = partition(arr, low, high);
            quick_sort(arr, low, pivot-1);
            quick_sort(arr, pivot+1, high);
        }
    }

    std::vector<T> sort_data()
    {
        quick_sort(&data_list, 0, data_list.size()-1);
        return data_list;
    }

};


#endif //PROJECT2_QUICK_H
