#include "./ShrubberyCreationForm.hpp"

ShrubberyCreationForm :: ShrubberyCreationForm(void) : AForm("No name", 145, 137, "Shrubbery Creation Form")
{
    std::cout << "Shrubbery Form is created" << std::endl;
    this->_target = "No name";
}

ShrubberyCreationForm :: ShrubberyCreationForm(ShrubberyCreationForm const &copy) : AForm(copy._target, 145, 137, "Shrubbery Creation Form")
{
    std::cout << "Shrubbery Form was copied" << std::endl;

    *this = copy;
}

ShrubberyCreationForm & ShrubberyCreationForm :: operator=(ShrubberyCreationForm const &rhs)
{
    if (this != &rhs)
        this->_target = rhs.getTarget();
    
    return *this;
}

ShrubberyCreationForm :: ~ShrubberyCreationForm(void)
{
    std::cout << "Shrubbery Form was destroyed" << std::endl;
}

ShrubberyCreationForm :: ShrubberyCreationForm(std::string target) : AForm(target, 145, 137, "Shrubbery Creation Form")
{
    std::cout << "Shrubbery Form is created" << std::endl;
    this->_target = target;
}

void ShrubberyCreationForm :: action() const
{
    std::ofstream file;
    file.open(this->_target + "_shrubbery");

    file << "          .     .  .      +     .      .          ." << std::endl;
    file << "     .       .      .     #       .           ." << std::endl;
    file << "        .      .         ###            .      .      ." << std::endl;
    file << "      .      .   \"#:. .:##\"##:. .:#\"  .      ." << std::endl;
    file << "          .      . \"####\"###\"####\"  ." << std::endl;
    file << "       .     \"#:.    .:#\"###\"#:.    .:#\"  .        .       ." << std::endl;
    file << "  .             \"#########\"#########\"        .        ." << std::endl;
    file << "        .    \"#:.  \"####\"###\"####\"  .:#\"   .       ." << std::endl;
    file << "     .     .  \"#######\"\"##\"##\"\"#######\"                  ." << std::endl;
    file << "                .\"##\"#####\"#####\"##\"           .      ." << std::endl;
    file << "    .   \"#:. ...  .:##\"###\"###\"##:.  ... .:#\"     ." << std::endl;
    file << "      .     \"#######\"##\"#####\"##\"#######\"      .     ." << std::endl;
    file << "    .    .     \"#####\"\"#######\"\"#####\"    .      ." << std::endl;
    file << "            .     \"      000      \"    .     ." << std::endl;
    file << "       .         .   .   000     .        .       ." << std::endl;
    file << ".. .. ..................O000O........................ ...... ..." << std::endl;   

    std::cout << "The tree was created, find it in the file: " << this->_target << "_shrubbery" << std::endl; 
}

void ShrubberyCreationForm :: execute(Bureaucrat const &executor) const
{
    if (executor.getGrade() > this->getExecGrade())
        throw AForm::GradeTooLowException();
    else if (this->getSignStatus() == false)
        throw AForm::FormNotSignedException();
    else
        this->action();
}

std::string ShrubberyCreationForm :: getTarget(void) const
{
    return this->_target;
}