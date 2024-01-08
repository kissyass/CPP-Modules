#include "./Bureaucrat.hpp"
#include "./AForm.hpp"
#include "./ShrubberyCreationForm.hpp"
#include "./RobotomyRequestForm.hpp"
#include "./PresidentialPardonForm.hpp"

int main()
{
   {
        Bureaucrat bureaucrat("Ken", 1);
        AForm *form;

        form = new ShrubberyCreationForm("Johny");
        std::cout << bureaucrat << std::endl;
        std::cout << *form << std::endl;
        bureaucrat.signForm(*form);
        bureaucrat.executeForm(*form);
        delete form;

        std::cout << "-----------------------------------------------------------------------------" << std::endl;

        form = new RobotomyRequestForm("Robot");
        std::cout << bureaucrat << std::endl;
        std::cout << *form << std::endl;
        bureaucrat.signForm(*form);
        bureaucrat.executeForm(*form);
        delete form;
        
        std::cout << "-----------------------------------------------------------------------------" << std::endl;

        form = new PresidentialPardonForm("President");
        std::cout << bureaucrat << std::endl;
        std::cout << *form << std::endl;
        bureaucrat.signForm(*form);
        bureaucrat.executeForm(*form);
        delete form;
    }

    std::cout << "------------------------------------------------------------------------------------------------------------------------------------" << std::endl;

    try 
    {
        Bureaucrat bureaucrat("Ken", 1);
        ShrubberyCreationForm form("Forest");

        std::cout << bureaucrat << std::endl;
        std::cout << form << std::endl;

        bureaucrat.executeForm(form);
    } 
    catch (AForm::FormNotSignedException &e) 
    {
        std::cout << "Oh oh, problem occured: " << e.what() << std::endl;   
    }

    try 
    {
        std::cout << "-----------------------------------------------------------------------------" << std::endl;

        Bureaucrat bureaucrat("Ken", 50);
        RobotomyRequestForm form("Roll");

        std::cout << bureaucrat << std::endl;
        std::cout << form << std::endl;

        bureaucrat.signForm(form);
        bureaucrat.executeForm(form);
    }
    catch (AForm::GradeTooLowException &e)
    {
        std::cout << "Oh oh, problem occured: bureaucrat's " << e.what() << std::endl;   
    }

    try 
    {
        std::cout << "-----------------------------------------------------------------------------" << std::endl;

        Bureaucrat bureaucrat("Ken", 100);
        PresidentialPardonForm form("Perk");

        std::cout << bureaucrat << std::endl;
        std::cout << form << std::endl;

        bureaucrat.signForm(form);
        bureaucrat.executeForm(form);
    }
    catch (AForm::GradeTooLowException &e)
    {
        std::cout << "Oh oh, problem occured: bureaucrat's " << e.what() << std::endl;   
    }
}