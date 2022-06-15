#ifndef WINNER_H
# define WINNER_H

#include <iostream>
#include <fstream>
#include <string>

class Winner
{

    private:

        std::string     _s1; 
        std::string     _s2;
        std::string     _filename;
        std::string     _newfile;

    public:

        Winner(std::string str1, std::string str2, std::string file);
        ~Winner();

        void    setNewFile();
};

#endif