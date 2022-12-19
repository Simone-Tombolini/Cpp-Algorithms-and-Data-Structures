#include "MergeSort.h"

#include <iostream>

int main(){
    int ai[] = {4, 5, 1, 3, 2};
    std::cout<<"not sorted array of int"<<std::endl;
     for (int i = 0; i <= 4; ++i){
        std::cout<<ai[i]<<std::endl;
    }
    
    merge_sort(ai, 0, 4, minor_than_int);
    
    std::cout<<"des. sorted array of int"<<std::endl;
    for (int i = 0; i <= 4; ++i){
        std::cout<<ai[i]<<std::endl;
    }
    
    merge_sort(ai, 0, 4, grater_than_int);

    std::cout<<"gro. sorted array of int"<<std::endl;
    for (int i = 0; i <= 4; ++i){
        std::cout<<ai[i]<<std::endl;
    }

    double ad[] = {4.1, 4.05, 3.2, 1.0001, 2};
    std::cout<<"not sorted array of double"<<std::endl;
    for (int i = 0; i <= 4; ++i){
        std::cout<<ad[i]<<std::endl;
    }

    std::cout<<"des. sorted array of double"<<std::endl;
    merge_sort(ad, 0, 4, minor_than_double);
    for (int i = 0; i <= 4; ++i){
        std::cout<<ad[i]<<std::endl;
    }
     //   int a[] = {4, 5, 1, 3,2};
    std::cout<<"gro. sorted array of double"<<std::endl;
    merge_sort(ad, 0, 4, grater_than_double);
    for (int i = 0; i <= 4; ++i){
        std::cout<<ad[i]<<std::endl;
    }
}