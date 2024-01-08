#include "./Intern.hpp"

Intern :: Intern(void)
{}

Intern :: Intern(AForm const &copy)
{
    *this = copy;
}

Intern & Intern :: operator=(Intern const &rhs)
{
    (void)rhs;

    return *this;
}

Intern :: ~Intern(void)
{}

AForm * Intern :: makeForm(std::string formName, std::string target)
{
    std::string forms[3] = {"shrubbery creation", "robotomy request", "presidential pardon"};
    int i;

    i = -1;
    while (++i < 3)
    {
        if (forms[i] == formName)
            break ;
    }

    switch (i)
    {
    case 0:
        std::cout << "Intern creates " << formName << " form" << std::endl;
        return new ShrubberyCreationForm(target);
        break;
    case 1:
        std::cout << "Intern creates " << formName << " form" << std::endl;
        return new RobotomyRequestForm(target);
        break;
    case 2:
        std::cout << "Intern creates " << formName << " form" << std::endl;
        return new PresidentialPardonForm(target);
        break;
    default:
        throw Intern::FormDoesNotExist();
    }
}