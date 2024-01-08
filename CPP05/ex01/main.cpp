#include "./Bureaucrat.hpp"
#include "Form.hpp"


int main()
{
    try 
    {
        Bureaucrat bureaucrat("Ken", 1);
        Form form("Document", 15);

        std::cout << bureaucrat << std::endl;
        std::cout << form << std::endl;

        bureaucrat.signForm(form);
        bureaucrat.signForm(form);
    } 
    catch (Bureaucrat::GradeTooHighException &e) 
    {
        std::cout << e.what() << std::endl;   
    }
    std::cout << "-----------------------------------------------------------------------------" << std::endl;
    try 
    {
        Bureaucrat worker;
        Form form;

        std::cout << worker << std::endl;
        std::cout << form << std::endl;

        worker.decrementGrade();
        worker.signForm(form);
    } 
    catch (Bureaucrat::GradeTooLowException &e) 
    {
        std::cout << e.what() << std::endl;   
    }
    return EXIT_SUCCESS;
}