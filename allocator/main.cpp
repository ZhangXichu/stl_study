#include "jjallocator.hpp"
#include "person.hpp"

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

    jj::allocator<Person> alloc_p;
    Person* person_ptr = alloc_p.allocate(1);

    alloc_p.construct(person_ptr, Person("Jhon Doe", 30));

    person_ptr->introduce();

    alloc_p.deallocate(person_ptr, 1);
}