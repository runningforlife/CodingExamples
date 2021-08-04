#include <iostream>
#include "sorting.h"


void SortAlg::insertSort(std::vector<int>& list) {
    if (list.size() <= 1) return;

    for (int i = 1; i < list.size(); ++i) {
	    for (int k = i; k > 0 && list[k] < list[k - 1]; --k) {
            int tmp = list[k];
            list[k] = list[k - 1];
            list[k - 1] = tmp;
        }
    }
}

void SortAlg::selectSort(std::vector<int>& list) {
    if (list.size() <= 1) return;

    for (int i = 0; i < list.size(); ++i) {
        int k = i;
        for (int j = i + 1; j < list.size(); ++j) {
            if (list[k] > list[j]) {
                k = j;
                int tmp = list[k];
                list[k] = list[i];
                list[i] = tmp;
            }
        }
    }
}

void SortAlg::bubbleSort(std::vector<int>& list) {
    if (list.size() <= 1) return;

    for (int i = 0; i < list.size(); ++i) {
        bool is_swapped = false;
        for (int j = i + 1; j < list.size(); ++j) {
            if (list[j] < list[j - 1]) {
                int tmp = list[j];
                list[j] = list[j - 1];
                list[j - 1] = tmp;
                is_swapped = true;
            }
        }
        
        if (!is_swapped) break;
    }
}

void SortAlg::quickSort(std::vector<int>& list, int s, int e) {
    if (s >= e) return;

    int pivot = (s + e)/2;
    swap(list, 1, pivot);

    
}

int main(int args, char *argv[]) 
{
    int arry[] = {1, 9 , 3, 5, 10, 89, 24, 23, 45};
    std::vector<int> list(arry, arry + sizeof(arry)/sizeof(int));    
    SortAlg *alg = new SortAlg();

    //alg->insertSort(list);    
    //alg->selectSort(list);
    alg->bubbleSort(list);
    std::cout << "sorting array list is" << std::endl;
    for (int i = 0; i < list.size(); ++i) {
        std::cout << list.at(i) << " ";
    }

    delete alg;    
}
