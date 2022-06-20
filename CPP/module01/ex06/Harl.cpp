#include "Harl.hpp"

void    Harl::debug()
{
    std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger. I really do!" << std::endl;
}

void    Harl::info()
{
    std::cout << "I cannot believe adding extra bacon costs more money. You didn't put enough bacon in my burger! If you did, I wouldn't be asking for more!" << std::endl;
}

void    Harl::warning()
{
    std::cout << "I think I deserve to have some extra bacon for free. I've been coming for years whereas you started working here since last month." << std::endl;
}

void    Harl::error()
{
    std::cout << "This is unacceptable! I want to speak to the manager now." << std::endl;
}

void    Harl::complain(std::string level)
{
    void    (Harl::*complaint[4])(void) = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};
    std::string levels[4] = {"debug", "info", "warning", "error"};
    int     i = -1;

    while (++i < 4)
        if (levels[i] == level)
            break;
    switch (i)
    {
    case 0:
        (this->*complaint[i])();
        break;
    case 1:
        (this->*complaint[i])();
        break;
    case 2:
        (this->*complaint[i])();
        break;
    case 3:
        (this->*complaint[i])();
        break;
    case 4:
        std::cout << "I am not sure how tired I am today..." << std::endl;
    }
}
