#include "Span.hpp"

int main()
{
    Span    a(5);

    try 
    {
        for(int i = 0; i < 10; ++i)
        {
            a.addNumber(i);
            std::cout << i << std::endl;
        }
    }
    catch(Span::MaxReachedException & e)
    {
        std::cout << e.what() << std::endl;
    }

    return (0);
}