#include "classes.hpp"

Form::Form()
{
    std::cout << "Form Constructor Called" << std::endl;
}

Form::Form(std::string name, int toSign, int toExec) : _name(name), _gradeToSign(toSign), _gradeToExec(toExec)
{
    if (toSign < 1 || toExec < 1)
        throw Form::GradeTooHighException();
    else if (toSign > 150 || toExec > 150)
        throw Form::GradeTooLowException();
    else
    {
        this->_isSigned = false;
        std::cout << "+Form" << " " << name << std::endl;
    }
}

Form::Form(Form & src)
{
    *this = src;
}

Form&     Form::operator=(Form & rhs)
{
    this->_name = rhs._name;
    this->_isSigned = rhs._isSigned;
    this->_gradeToSign = rhs._gradeToSign;
    this->_gradeToExec = rhs._gradeToExec;

    return (*this);
}

Form::~Form()
{
    std::cout << "-Form" << " " << this->_name << std::endl;
}

std::string     Form::getName() const
{
    return (this->_name);
}

bool    Form::getIsSigned() const
{
    return (this->_isSigned);
}

int     Form::getToSign() const
{
    return (this->_gradeToSign);
}

int     Form::getToExec() const
{
    return (this->_gradeToExec);
}

std::ostream &  operator<<(std::ostream &o, Form & src)
{
    o << "FORM" << std::endl;
    o << "Name :" << " " << src.getName() << std::endl;
    if (src.getIsSigned() == true)
        o << "Signed : Yes." << std::endl;
    else
        o << "Signed : No." << std::endl;
    o << "Grade for sign" << " " << src.getToSign() << std::endl;
    o << "Grade for exec" << " " << src.getToExec() << std::endl;
    return (o);
}

void    Form::beSigned(Bureaucrat src)
{
    if (src.getGrade() <= this->getToSign())
        this->_isSigned = true;
    else
        throw (Form::GradeTooLowException());
}


