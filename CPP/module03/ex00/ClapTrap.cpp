#include "ClapTrap.hpp"

ClapTrap::ClapTrap(std::string name, int hit, int energy, int attack) : 
_name(name),
_hitPoints(hit),
_EnergyPoints(energy),
_AttackDamage(attack)
{
    std::cout << "ClapTrap Constructor Called" << std::endl;
}

ClapTrap::~ClapTrap()
{
    std::cout << "ClapTrap Destructor Called" << std::endl;
}

void    ClapTrap::attack(const std::string& target)
{
    if (this->_EnergyPoints > 0 && this->_hitPoints > 0)
    {
        std::cout << "ClapTrap " << this->_name;
        std::cout << " attacks " << target;
        std::cout << " causing " << this->_AttackDamage;
        std::cout << " points of damage!" << std::endl;
        this->_EnergyPoints -= 1;
    }
    else if (this->_hitPoints <= 0)
        std::cout << "is Dead." << std::endl;
    else
        std::cout << "Missing energy." << std::endl;
}

void    ClapTrap::takeDamage(unsigned int amount)
{
    if (this->_hitPoints > 0)
    {
        std::cout << "ClapTrap " << this->_name;
        std::cout << " takes " << amount;
        std::cout << " points of damage !";
        this->_hitPoints -= amount;
        std::cout << " Life now : " << this->_hitPoints << std::endl;
        std::cout << "Meme pas mal" << std::endl;
    }
    else
        std::cout << this->_name << " is dead." << std::endl;
}

void    ClapTrap::beRepaired(unsigned int amount)
{
    if (this->_EnergyPoints > 0 && this->_hitPoints > 0)
    {
        std::cout << "ClapTrap " << this->_name;
        std::cout << " gained " << amount;
        std::cout << " life points !" << std::endl;
        this->_EnergyPoints -= 1;
    }
    else if (this->_hitPoints <= 0)
        std::cout << this->_name << " is Dead." << std::endl;
    else
        std::cout << "Missing energy." << std::endl;

}

unsigned int     ClapTrap::getAttackDamage()
{
    return ((unsigned int)this->_AttackDamage);
}