#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <cstdlib>

// A * a_class()
// {
//     A   *a;

//     return(a);
// }

// B * b_class()
// {
//     B   *b;

//     return(b);
// }
// C * c_class()
// {
//     C   *c;

//     return(c);
// }

// Base *  generate(void)
// {
//     int nbr;

//     srand (time(NULL));
//     nbr = rand() % 3;

//     if (nbr == 0)
//     {
//         A   *a;
//         return (a);
//     }
//     else if (nbr == 1)
//     {
//         B   *b;
//         return (b);
//     }
//     else if (nbr == 2)
//     {
//         C   *c;
//         return (c);
//     }
//     return NULL;
// }

void identify(Base* p)
{
    (void)p;
}

void identify(Base& p)
{
    (void)p;
}

int main()
{
    Base    *p;
    
    //std::cout << p << std::endl;
    p = generate();
    std::cout << p << std::endl;
    return 0;
}