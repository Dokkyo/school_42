#include "ClapTrap.hpp"

int main()
{
    ClapTrap    Johnny("Johnny", 10, 10, 0);
    ClapTrap    Amber("Amber", 10, 10, 0);
    int         i = 0;
    
    while (i++ < 10)
    {
        Amber.attack("Johnny");
        Johnny.takeDamage(Amber.getAttackDamage());
        std::cout << std::endl;
    }
    Amber.attack("Johnny");
    Amber.beRepaired(1);
    Johnny.beRepaired(1);

    return (0);
}