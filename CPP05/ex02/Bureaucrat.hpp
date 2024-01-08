#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

# include <iostream>
# include "AForm.hpp"

class AForm;

class Bureaucrat
{
    private:
        const std::string _name;
        int _grade;
    public:
        Bureaucrat(void);
        Bureaucrat(Bureaucrat const &copy);
        Bureaucrat & operator=(Bureaucrat const &rhs);
        ~Bureaucrat(void);
        Bureaucrat(std::string name, int grade);
        std::string getName(void) const;
        int getGrade(void) const;
        void  incrementGrade();
        void  decrementGrade();
        
        void signForm(AForm &form);
        void executeForm(AForm const &form);
    /*******************************************EXCEPTION-CLASSES*******************************************/
    class GradeTooHighException : public std::exception {
        public:
            virtual const char* what() const throw() { return "Grade is too high"; }
    };
    class GradeTooLowException : public std::exception {
        public:
            virtual const char* what() const throw() { return "Grade is too low"; }
    };
};

std::ostream & operator<<(std::ostream &output, const Bureaucrat &worker);

#endif