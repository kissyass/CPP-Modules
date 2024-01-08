#include "./PresidentialPardonForm.hpp"

PresidentialPardonForm :: PresidentialPardonForm(void) : AForm("No name", 25, 5, "Presidential Pardon Form")
{
    std::cout << "Presidential Form is created" << std::endl;
    this->_target = "No name";
}

PresidentialPardonForm :: PresidentialPardonForm(PresidentialPardonForm const &copy) : AForm(copy._target, 72, 45, "Presidential Pardon Form")
{
    std::cout << "Presidential Form was copied" << std::endl;

    *this = copy;
}

PresidentialPardonForm & PresidentialPardonForm :: operator=(PresidentialPardonForm const &rhs)
{
    if (this != &rhs)
        this->_target = rhs.getTarget();
    
    return *this;
}

PresidentialPardonForm :: ~PresidentialPardonForm(void)
{
    std::cout << "Presidential Form was destroyed" << std::endl;
}

PresidentialPardonForm :: PresidentialPardonForm(std::string target) : AForm(target, 25, 5,  "Presidential Pardon Form")
{
    std::cout << "Presidential Form is created" << std::endl;
    this->_target = target;
}

void PresidentialPardonForm :: action() const
{
    std::cout << this->_target << " has been pardoned by Zaphod Beeblebrox" << std::endl;
}

void PresidentialPardonForm :: execute(Bureaucrat const &executor) const
{
    if (executor.getGrade() > this->getExecGrade())
        throw AForm::GradeTooLowException();
    else if (this->getSignStatus() == false)
        throw AForm::FormNotSignedException();
    else
        this->action();
}

std::string PresidentialPardonForm :: getTarget(void) const
{
    return this->_target;
}