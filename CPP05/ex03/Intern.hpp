#ifndef INTERN_HPP
# define INTERN_HPP

#include "./AForm.hpp"
#include "./ShrubberyCreationForm.hpp"
#include "./RobotomyRequestForm.hpp"
#include "./PresidentialPardonForm.hpp"

class Intern
{
    public:
        Intern(void);
        Intern(AForm const &copy);
        Intern &operator=(Intern const &rhs);
        ~Intern(void);
        AForm * makeForm(std::string formName, std::string target);
        
        /*******************************************EXCEPTION-CLASSES*******************************************/
        class FormDoesNotExist : public std::exception
        {
            public:
            virtual const char *what() const throw()
            {
                return ("such form doesn't exist");
            }
        };
};

#endif