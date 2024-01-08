#include "./RobotomyRequestForm.hpp"

RobotomyRequestForm :: RobotomyRequestForm(void) : AForm("No name", 72, 45, "Robotomy Request Form")
{
    std::cout << "Robotomy Form is created" << std::endl;
    this->_target = "No name";
}

RobotomyRequestForm :: RobotomyRequestForm(RobotomyRequestForm const &copy) : AForm(copy._target, 72, 45, "Robotomy Request Form")
{
    std::cout << "Robotomy Form was copied" << std::endl;

    *this = copy;
}

RobotomyRequestForm & RobotomyRequestForm :: operator=(RobotomyRequestForm const &rhs)
{
    if (this != &rhs)
        this->_target = rhs.getTarget();
    
    return *this;
}

RobotomyRequestForm :: ~RobotomyRequestForm(void)
{
    std::cout << "Robotomy Form was destroyed" << std::endl;
}

RobotomyRequestForm :: RobotomyRequestForm(std::string target) : AForm(target, 72, 45, "Robotomy Request Form")
{
    std::cout << "Robotomy Form is created" << std::endl;
    this->_target = target;
}

void RobotomyRequestForm :: action() const
{
    srand (time(NULL));
    std::cout << "Bzzz... drilling noises... Bzzz..." << std::endl;
    if (rand() % 2 == 1)
		std::cout << this->_target << " has been robotomized successfully." << std::endl;
	else
		std::cout << this->_target << " robotomization has failed." << std::endl;
}

void RobotomyRequestForm :: execute(Bureaucrat const &executor) const
{
    if (executor.getGrade() > this->getExecGrade())
        throw AForm::GradeTooLowException();
    else if (this->getSignStatus() == false)
        throw AForm::FormNotSignedException();
    else
        this->action();
}

std::string RobotomyRequestForm :: getTarget(void) const
{
    return this->_target;
}