#ifndef FORM_HPP
#define FORM_HPP

# include "./Bureaucrat.hpp"

class Bureaucrat;

class Form
{
    private:
        const std::string _name;
        bool _isSigned;
        const int _signGrade;
        const int _execGrade;
    public:
        Form(void);
        Form(Form const &copy);
        Form & operator=(Form const &rhs);
        ~Form(void);
        Form(std::string name, int grade);
        std::string getName(void) const;
        bool getSignStatus(void) const;
        int getSignGrade(void) const;
        int getExecGrade(void) const;
        void beSigned(Bureaucrat const &worker);
        /*******************************************EXCEPTION-CLASSES*******************************************/
        class GradeTooHighException : public std::exception {
            public:
                virtual const char* what() const throw() { return "grade is too high"; }
        };
        class GradeTooLowException : public std::exception {
            public:
                virtual const char* what() const throw() { return "grade is too low"; }
        };
};

std::ostream & operator<<(std::ostream &output, const Form &form);

#endif