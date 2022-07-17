#include <vector> 
#include <iostream>

template<typename T>
int   easyfind(T container, int occur)
{
    for(size_t i = 0; i < container.size(); ++i)
    {
        if (container[i] == occur)
        {
            std::cout << "Occurrence finded : " << container[i] << std::endl;
            return (0);
        }
    }
    return (1);
}
