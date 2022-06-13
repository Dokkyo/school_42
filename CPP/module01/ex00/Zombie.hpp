#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

#include <iostream>
#include <string>

class Zombie {

    public:

        void    announce(void);
        Zombie* newZombie( std::string name );
        void randomChump( std::string name );

    private:
        std::string _name;
};


#endif
