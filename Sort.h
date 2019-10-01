#ifndef PROJECT2_SORT_H
#define PROJECT2_SORT_H

#include <vector>

template <class T>
class Sort
{
protected:
    std::vector<T> *data_list_ptr;

public:
    Sort() = default;

    explicit Sort(std::vector<T>* data_list_ptr) : data_list_ptr{data_list_ptr} {};

    void point_to(std::vector<T>* ptr)
    {
        data_list_ptr = ptr;
    }

    virtual std::vector<T> sort_data() = 0;
};
#endif //PROJECT2_SORT_H
