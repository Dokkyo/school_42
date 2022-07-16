#include "iter.hpp"

int main( void ) 
{
    float tab[10];
    int i = -1;

    while (++i < 10)
        tab[i] = i + 1;
    i = -1;
    while (++i < 10)
        std::cout << std::fixed << std::setprecision(1) << "Tab element " << i << ": " << tab[i] << std::endl;
    std::cout << std::endl;
    ::iter(tab, 10.0f, ::add);
    
    std::cout << std::endl;
    std::cout << "---------------------------------------------" << std::endl;
    int tab2[10];
    i = -1;
    while (++i < 10)
        tab2[i] = i + 10;
    i = -1;
    while (++i < 10)
        std::cout << std::fixed << std::setprecision(1) << "Tab element " << i << ": " << tab2[i] << std::endl;
    std::cout << std::endl;
    ::iter(tab2, 10, ::add);

    return 0;
}