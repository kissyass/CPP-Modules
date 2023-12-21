#include "./Form.hpp"

Form :: Form(void) : _name("Default form"), _gradeSign(75), _gradeExec(0), _isSigned(false)
{   
}

Form :: Form(Form const &copy) : _name(copy._name), _gradeSign(copy._gradeSign), _gradeExec(copy._gradeExec)
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

Form :: Form(std::string name, int grade) : _name(name), _gradeSign(grade), _gradeExec(0), _isSigned(false)
{
}

std::string Form :: getName(void) const
{
    return this->_name;
}

int Form :: getGradeSign(void) const
{
    return this->_gradeSign;
}

int Form :: getGradeExec(void) const
{
    return this->_gradeExec;
}

bool Form :: getIsSigned(void) const
{
    return this->_isSigned;
}

void Form :: beSigned(Bureaucrat const &bureaucrat)
{
    if (bureaucrat.getGrade() <= this->_gradeSign)
        this->_isSigned = true;
    else
        throw Form::GradeTooLowException();
}

std::ostream & operator<<(std::ostream &output, const Form &form)
{
    output << "Form name: " << form.getName() << ", form sign status: " << form.getIsSigned()
            << ", form sign grade: " << form.getGradeSign() << "; form execute grade: "
            << form.getGradeExec() << std::endl;

    return output;
}