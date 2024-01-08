#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

#include "./AForm.hpp"
#include <fstream>

class ShrubberyCreationForm : public AForm
{
  private:
    std::string _target;
  public:
	ShrubberyCreationForm(void);
	ShrubberyCreationForm(ShrubberyCreationForm const &copy);
	ShrubberyCreationForm &operator=(ShrubberyCreationForm const &rhs);
	~ShrubberyCreationForm(void);
	ShrubberyCreationForm(std::string target);

	void action() const;
	void execute(Bureaucrat const &executor) const;
    std::string getTarget(void) const;
};

#endif