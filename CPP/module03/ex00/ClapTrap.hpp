#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

#include <iostream>
#include <string>

class ClapTrap
{
    private:

        std::string     _name;
        int             _hitPoints;
        int             _EnergyPoints;
        int             _AttackDamage;

    public:
        
        ClapTrap(std::string name, int hit, int energy, int attack);
        ~ClapTrap();

        unsigned int     getAttackDamage();

        void    attack(const std::string& target);
        void    takeDamage(unsigned int amount);
        void    beRepaired(unsigned int amount);
};




#endif