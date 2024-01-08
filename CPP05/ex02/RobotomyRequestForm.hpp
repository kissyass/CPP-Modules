#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

#include "./AForm.hpp"
#include <time.h>

class RobotomyRequestForm : public AForm
{
  private:
    std::string _target;
  public:
	RobotomyRequestForm(void);
	RobotomyRequestForm(RobotomyRequestForm const &copy);
	RobotomyRequestForm &operator=(RobotomyRequestForm const &rhs);
	~RobotomyRequestForm(void);
	RobotomyRequestForm(std::string target);

	void action() const;
	void execute(Bureaucrat const &executor) const;
    std::string getTarget(void) const;
};

#endif