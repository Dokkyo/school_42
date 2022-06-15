#include "HumanB.hpp"

HumanB::HumanB(std::string name) : _name(name)
{
    std::cout << "HumanB called" << std::endl;
}

HumanB::~HumanB()
{
        std::cout << "HumanB destroyed" << std::endl;
}

void    HumanB::attack()
{
    std::cout << this->_name << " attacks with their ";
    std::cout << this->_weapon->getType() << std::endl;
}

void    HumanB::setWeapon(Weapon *weapon)
{
    this->_weapon = weapon;
}