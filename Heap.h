
#ifndef PROJECT2_HEAP_H
#define PROJECT2_HEAP_H

#include "Sort.h"
#include <cmath>

template <class T>
class Heap : public Sort<T>
{
private:
    std::vector<T> data_list;
    int data_max;

    void heapify(std::vector<T>*arr, int n, int i)
    {
        int max = i;
        int left = 2 * i + 1;
        int right = 2 * i + 2;

        if (left < n && arr->at(left) > arr->at(max))
            max = left;

        if (right < n && arr->at(right) > arr->at(max))
            max = right;

        if (max != i)
        {
            iter_swap(arr->begin()+i, data_list.begin() + max);
            heapify(arr, n, max);
        }
    }

public:
    Heap() : Sort<T>() {};
    explicit Heap(std::vector<T>* data_list_ptr) : Sort<T>(data_list_ptr)
    {
        data_list = *data_list_ptr;
        data_max = data_list.size() - 1;
    };
    std::vector<T> sort_data()
    {
        for (int i = data_max/2 - 1; i >= 0; --i)
            heapify(&data_list, data_max, i);

        for (int i = data_max-1; i>=0; --i)
        {
            iter_swap(data_list.begin(), data_list.begin() + i);
            heapify(&data_list, i, 0);
        }
        return data_list;
    }

};
#endif //PROJECT2_HEAP_H
