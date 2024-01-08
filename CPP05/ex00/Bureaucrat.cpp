#include "./Bureaucrat.hpp"

Bureaucrat::Bureaucrat(void) : _name("Default worker"), _grade(75)
{
}

Bureaucrat::Bureaucrat(Bureaucrat const &copy) : _name(copy._name)
{
    *this = copy;
}

Bureaucrat & Bureaucrat :: operator=(Bureaucrat const &rhs)
{
    if (this != &rhs)
        this->_grade = rhs._grade;
    
    return *this;
}

Bureaucrat::~Bureaucrat(void)
{
}

Bureaucrat::Bureaucrat(std::string name, int grade) : _name(name), _grade(grade)
{
    if (grade < 1)
        throw Bureaucrat::GradeTooHighException();
    if (grade > 150)
        throw Bureaucrat::GradeTooLowException();
}

std::string Bureaucrat :: getName(void) const
{
    return this->_name;
}

int Bureaucrat :: getGrade(void) const
{
    return this->_grade;
}

void    Bureaucrat::incrementGrade() {
    if ( _grade - 1 < 1 )
        throw Bureaucrat::GradeTooHighException();
    _grade--;
}

void    Bureaucrat::decrementGrade() {
    if ( _grade + 1 > 150 )
        throw Bureaucrat::GradeTooLowException();
    _grade++;
}

std::ostream & operator<<(std::ostream &output, const Bureaucrat &worker)
{
    output << worker.getName() << ", bureaucrat grade " << worker.getGrade() << ".";

    return output;
}