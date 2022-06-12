#ifndef CONTACT_HPP
# define CONTACT_HPP

#include <iostream>
#include <string>

class Contact {

    public:

        void    setInfo(std::string *data, std::string str);
        void    askInfo( void );
        std::string    Name( void );
        std::string    LastName( void );
        std::string    NickName( void );
        std::string    PhoneNumber( void );
        std::string    DarkestSecret( void );

    private:
        std::string    _Name;
        std::string    _LastName;
        std::string    _NickName;
        std::string    _PhoneNumber;
        std::string    _DarkestSecret;
};

#endif