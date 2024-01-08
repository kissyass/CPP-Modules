#include "./Bureaucrat.hpp"

int main()
{
    try 
    {
        Bureaucrat bureaucrat("Ken", 1);

        std::cout << bureaucrat << std::endl;

        std::cout << "Incrementing grade" << std::endl;
        bureaucrat.incrementGrade();
        std::cout << "Decrementing grade" << std::endl;
        bureaucrat.decrementGrade();
    } 
    catch (Bureaucrat::GradeTooHighException &e) 
    {
        std::cout << "Oh oh, problem occured: " << e.what() << std::endl;   
    }
    std::cout << "-----------------------------------------------------------------------------" << std::endl;

    try 
    {
        Bureaucrat worker;

        std::cout << worker << std::endl;

        while (worker.getGrade() < 150)
            worker.decrementGrade();
        
        std::cout << worker << std::endl;
        std::cout << "Decrementing grade last time" << std::endl;
        worker.decrementGrade();
    } 
    catch (Bureaucrat::GradeTooLowException &e) 
    {
        std::cout << "Oh oh, problem occured: " << e.what() << std::endl;   
    }
    return EXIT_SUCCESS;
}