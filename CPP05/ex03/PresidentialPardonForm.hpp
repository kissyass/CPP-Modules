#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP

#include "./AForm.hpp"

class PresidentialPardonForm : public AForm
{
  private:
    std::string _target;
  public:
	PresidentialPardonForm(void);
	PresidentialPardonForm(PresidentialPardonForm const &copy);
	PresidentialPardonForm &operator=(PresidentialPardonForm const &rhs);
	~PresidentialPardonForm(void);
	PresidentialPardonForm(std::string target);

	void action() const;
	void execute(Bureaucrat const &executor) const;
    std::string getTarget(void) const;
};

#endif