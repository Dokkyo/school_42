#include "Winner.hpp"

Winner::Winner(std::string str1, std::string str2, std::string file) : _s1(str1), _s2(str2), _filename(file)
{
    std::cout << "Constructor called" << std::endl;
}

Winner::~Winner()
{
    std::cout << "Destructor called" << std::endl;
}

void    Winner::setNewFile()
{
    std::ifstream   ifs(this->_filename.c_str());
    
    
    this->_newfile = this->_filename + ".replace";
    std::ofstream   ofs(this->_newfile.c_str());

    ifs.close();
}