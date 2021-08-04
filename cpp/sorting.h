#ifndef _SORTING_H
#define _SORTING_H

#include <vector>

class SortAlg {
public:
    SortAlg() {}
    ~SortAlg() {}

    void insertSort(std::vector<int>& list);

    void selectSort(std::vector<int>& list);

    void bubbleSort(std::vector<int>& list);

    void quickSort(std::vector<int>& list, int s, int e);

private:
    void swap(std::vector<int>& list, int i, int j) {
        int tmp = list[i];
        list[i] = list[j];
        list[j] = tmp; 
    }
};

#endif
