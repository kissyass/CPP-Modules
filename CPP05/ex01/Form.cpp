#include "Form.hpp"

Form :: Form(void) : _name("Default Form"),  _signGrade(75), _execGrade(1)
{
    this->_isSigned = false;
}

Form :: Form(Form const &copy) : _name(copy._name), _signGrade(copy._signGrade), _execGrade(copy._execGrade)
{
    *this = copy;
}

Form & Form :: operator=(Form const &rhs)
{
    if (this != &rhs)
        this->_isSigned = rhs._isSigned;
    
    return *this;
}

Form :: ~Form(void)
{
}

Form :: Form(std::string name, int grade) : _name(name), _signGrade(grade), _execGrade(1)
{
    this->_isSigned = false;
    if (grade < 1)
        throw Form::GradeTooHighException();
    if (grade > 150)
        throw Form::GradeTooLowException();
}

std::string Form :: getName(void) const
{
    return this->_name;
}

bool Form :: getSignStatus(void) const
{
    return this->_isSigned;
}

int Form :: getSignGrade(void) const
{
    return this->_signGrade;
}

int Form :: getExecGrade(void) const
{
    return this->_execGrade;
}

void Form :: beSigned(Bureaucrat const &worker)
{
    if (worker.getGrade() <= this->_signGrade)
        _isSigned = true;
    else
        throw Form::GradeTooLowException();
}

std::ostream & operator<<(std::ostream &output, const Form &form)
{
    output << "Form name: " << form.getName() << "; signing status: " << form.getSignStatus() << "; sign grade: " << form.getSignGrade() << "; execution grade: " << form.getExecGrade() << std::endl;

    return output;
}