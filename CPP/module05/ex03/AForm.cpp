#include "classes.hpp"

AForm::AForm(std::string name, int toSign, int toExec) : _name(name), _gradeToSign(toSign), _gradeToExec(toExec)
{
    if (toSign < 1 || toExec < 1)
        throw AForm::GradeTooHighException();
    else if (toSign > 150 || toExec > 150)
        throw AForm::GradeTooLowException();
    else
    {
        this->_isSigned = false;
        std::cout << "+AForm" << " " << name << std::endl;
    }
}

AForm::AForm(AForm & src)
{
    *this = src;
}

AForm&     AForm::operator=(AForm & rhs)
{
    this->_name = rhs._name;
    this->_isSigned = rhs._isSigned;
    this->_gradeToSign = rhs._gradeToSign;
    this->_gradeToExec = rhs._gradeToExec;

    return (*this);
}

AForm::~AForm()
{
    std::cout << "-AForm" << " " << this->_name << std::endl;
}

std::string     AForm::getName() const
{
    return (this->_name);
}

bool    AForm::getIsSigned() const
{
    return (this->_isSigned);
}

int     AForm::getToSign() const
{
    return (this->_gradeToSign);
}

int     AForm::getToExec() const
{
    return (this->_gradeToExec);
}

std::ostream &  operator<<(std::ostream &o, AForm & src)
{
    o << "FORM" << std::endl;
    o << "Name :" << " " << src.getName() << std::endl;
    if (src.getIsSigned() == true)
        o << "Signed : Yes" << std::endl;
    else
        o << "Signed : No" << std::endl;
    o << "Grade for sign" << " " << src.getToSign() << std::endl;
    o << "Grade for exec" << " " << src.getToExec() << std::endl;
    return (o);
}

void    AForm::beSigned(Bureaucrat & src)
{
    if (src.getGrade() <= this->getToSign())
        this->_isSigned = true;
    else
        throw (AForm::GradeTooLowException());
}

void            AForm::execute(Bureaucrat & executor)
{
    this->action(executor);
}
