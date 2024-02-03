#include "jjallocator.hpp"

#include <vector>
#include <iostream>

int main()
{
    int arr_int[5] = {0, 1, 2, 3, 4};
    unsigned int i;

    std::vector<int, jj::allocator<int>> int_vector(arr_int, arr_int+5); 

    for (i=0; i < int_vector.size(); i++)
    {
        std::cout << int_vector[i] << ' ';
    }
    std::cout << std::endl;


}