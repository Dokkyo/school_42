#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

#include <iostream>
#include <iomanip>
#include <string>
#include <cstring>
#include <cstdlib>
#include "Contact.hpp"

class PhoneBook {

    public:

        PhoneBook(int nb,int old);
        ~PhoneBook ();
        void        newContact();
        void        printRegistered();
        std::string checkFormat(int idx, std::string str);
        void        searchContact();

    private:

        int     nb_contact;
        int     idx;
        int     oldest;
        Contact contact[8];
};

#endif