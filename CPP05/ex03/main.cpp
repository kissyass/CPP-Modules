#include "./Bureaucrat.hpp"
#include "./AForm.hpp"
#include "./ShrubberyCreationForm.hpp"
#include "./RobotomyRequestForm.hpp"
#include "./PresidentialPardonForm.hpp"
#include "./Intern.hpp"

int main()
{
    try 
        {
            AForm *form;
            Intern intern;

            form = intern.makeForm("shrubbery creation", "Forest");
            std::cout << *form << std::endl;
            delete form;

            std::cout << "-----------------------------------------------------------------------------" << std::endl;

            form = intern.makeForm("robotomy request", "Robo");
            std::cout << *form << std::endl;
            delete form;
            
            std::cout << "-----------------------------------------------------------------------------" << std::endl;
            
            form = intern.makeForm("presidential pardon", "Presi");
            std::cout << *form << std::endl;
            delete form;
            
            std::cout << "-----------------------------------------------------------------------------" << std::endl;
            
            form = intern.makeForm("default", "no name");
            std::cout << *form << std::endl;
            delete form;
            
            std::cout << "-----------------------------------------------------------------------------" << std::endl;
        } 
    catch (Intern::FormDoesNotExist &e) 
        {
            std::cout << "Oh oh, a problem occured: " << e.what() << std::endl;  
        }
}