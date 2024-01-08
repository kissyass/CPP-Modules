#include "AForm.hpp"

AForm :: AForm(void) : _name("Default Form"),  _type("Default Form"), _signGrade(75), _execGrade(1)
{
    this->_isSigned = false;
}

AForm :: AForm(AForm const &copy) : _name(copy._name), _type(copy._type), _signGrade(copy._signGrade), _execGrade(copy._execGrade)
{
    *this = copy;
}

AForm & AForm :: operator=(AForm const &rhs)
{
    if (this != &rhs)
        this->_isSigned = rhs._isSigned;
    
    return *this;
}

AForm :: ~AForm(void)
{
    // std::cout << "Form is deleted" << std::endl;
}

AForm :: AForm(std::string name, int sign, int exec, std::string type) : _name(name), _type(type), _signGrade(sign), _execGrade(exec)
{
    // std::cout << "Form is created" << std::endl;
    this->_isSigned = false;
    if (sign < 1 || exec < 1)
        throw AForm::GradeTooHighException();
    if (sign > 150 || exec > 150)
        throw AForm::GradeTooLowException();
}

std::string AForm :: getName(void) const
{
    return this->_name;
}

std::string AForm :: getType(void) const
{
    return this->_type;
}

bool AForm :: getSignStatus(void) const
{
    return this->_isSigned;
}

int AForm :: getSignGrade(void) const
{
    return this->_signGrade;
}

int AForm :: getExecGrade(void) const
{
    return this->_execGrade;
}

void AForm :: beSigned(Bureaucrat const &worker)
{
    if (worker.getGrade() <= this->_signGrade)
        _isSigned = true;
    else
        throw AForm::GradeTooLowException();
}

std::ostream & operator<<(std::ostream &output, const AForm &form)
{
    output << "Form name: " << form.getName() << "; form type: " << form.getType() << "; signing status: " << form.getSignStatus() << "; sign grade: " << form.getSignGrade() << "; execution grade: " << form.getExecGrade();

    return output;
}