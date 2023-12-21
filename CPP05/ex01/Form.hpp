#ifndef FORM_HPP
#define FORM_HPP

#include "Bureaucrat.hpp"
#include <iostream>

class Form
{
    private:
        const std::string _name;
        bool _isSigned;
        const int _gradeSign;
        const int _gradeExec;
    public:
        Form(void);
        Form(Form const &copy);
        Form & operator=(Form const &rhs);
        ~Form(void);
        Form(std::string name, int grade);
        std::string getName(void) const;
        int getGradeSign(void) const;
        int getGradeExec(void) const;
        bool getIsSigned(void) const;
        void beSigned(Bureaucrat const &bureaucrat);

    /*******************************************EXCEPTION-CLASSES*******************************************/
    class GradeTooHighException : public std::exception {
        public:
            virtual const char* what() const throw() { return "grade too high"; }
    };
    class GradeTooLowException : public std::exception {
        public:
            virtual const char* what() const throw() { return "grade too low"; }
    };
};

std::ostream & operator<<(std::ostream &output, const Form &form);

#endif