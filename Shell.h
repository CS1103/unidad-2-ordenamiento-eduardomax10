#ifndef PROJECT2_SHELL_H
#define PROJECT2_SHELL_H
template <class T>
class Shell : public Sort<T>
{
private:
    std::vector<T> data_list;
    int data_max;

public:
    Shell() : Sort<T>() {};
    explicit Shell(std::vector<T>* data_list_ptr) : Sort<T>(data_list_ptr)
    {
        data_list = *data_list_ptr;
        data_max = data_list.size() - 1;

    };
    std::vector<T> sort_data()
    {
        for (int gap = data_max/2; gap > 0; gap /= 2)
            for (int i = gap; i < data_max; i += 1)
            {
                int temp = data_list[i];
                int j;
                for (j = i; j >= gap && data_list[j - gap] > temp; j -= gap)
                    data_list[j] = data_list[j - gap];
                data_list[j] = temp;
            }
        return data_list;
    }
};
#endif //PROJECT2_SHELL_H
