#include "PhoneBook.hpp"

PhoneBook::PhoneBook(int nb, int old) : nb_contact(nb), oldest(old) {}

PhoneBook::~PhoneBook() {}

void    PhoneBook::newContact()
{
    if (nb_contact == 8)
    {
        this->contact[oldest].askInfo();
        this->oldest++;
        if (this->oldest == 8)
            this->oldest = 0;
    }
    else
    {
        this->contact[nb_contact].askInfo();
        ++this->nb_contact;
    }
}

std::string    PhoneBook::checkFormat(int idx, std::string str)
{
    std::string strg;

    if (str == "First Name")
    {
        strg = this->contact[idx].Name().substr(0, 10);
        if (strg.size() < 10)
        {
            while (strg.size() < 10)
                strg.insert(0, 1, ' ');
        }
        else if (this->contact[idx].Name().size() > 10)
        {
            strg.replace(9, 1, 1,'.');
        }
        return (strg);
    }
    else if (str == "Last Name")
    {
        strg = this->contact[idx].LastName().substr(0, 10);
        if (strg.size() < 10)
        {
            while (strg.size() < 10)
                strg.insert(0, 1, ' ');
        }
        else if (this->contact[idx].LastName().size() > 10)
            strg.replace(9, 1, 1,'.');
        return (strg);
    }
    else if (str == "Nickname")
    {
        strg = this->contact[idx].NickName().substr(0, 10);
        if (strg.size() < 10)
        {
            while (strg.size() < 10)
                strg.insert(0, 1, ' ');
        }
        else if (this->contact[idx].NickName().size() > 10)
            strg.replace(9, 1, 1,'.');
        return (strg);
    }
    return (strg);
}

void    PhoneBook::printRegistered()
{
    int         idx = -1;
    std::string str;

    std::cout   << std::setfill(' ') << std::setw(10) << "Index";
    std::cout   << "|";
    std::cout   << std::setfill(' ') << std::setw(10) << "First Name";
    std::cout   << "|";
    std::cout   << std::setfill(' ') << std::setw(10) << "Last Name";
    std::cout   << "|";
    std::cout   << std::setfill(' ') << std::setw(10) << "Nickname" << std::endl;
    while (++idx < this->nb_contact)
    {
        std::cout << std::setfill(' ') << std::setw(10) << idx + 1;
        str = checkFormat(idx, "First Name");
        std::cout << " " << str;
        str = checkFormat(idx, "Last Name");
        std::cout << " " << str;
        str = checkFormat(idx, "Nickname");
        std::cout << " " << str << std::endl;
    }
}

void    PhoneBook::searchContact()
{
    std::string     str;
    int             idx;

    printRegistered();
    while (str.empty())
    {
        std::cout << "Index du contact : ";
        std::getline(std::cin, str);
        if (std::cin.eof()) {
            break;
        }
    }
    idx = std::atoi(str.c_str());
    if (idx >= 1 && idx <= this->nb_contact)
    {
        std::cout << this->contact[idx - 1].Name() << std::endl;
        std::cout << this->contact[idx - 1].LastName() << std::endl;
        std::cout << this->contact[idx - 1].NickName() << std::endl;
        std::cout << this->contact[idx - 1].PhoneNumber() << std::endl;
        std::cout << this->contact[idx - 1].DarkestSecret() << std::endl;
    }
    else if (idx >= 1 && idx <= 8)
        std::cout << "Aucun contact enregistré." << std::endl;
    else
        std::cout << "Indiquer une valeur entre 1 et 8." << std::endl;
}