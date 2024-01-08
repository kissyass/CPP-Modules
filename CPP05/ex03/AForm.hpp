#ifndef AFORM_HPP
# define AFORM_HPP

# include "./Bureaucrat.hpp"

class	Bureaucrat;

class AForm
{
  private:
	const std::string _name;
	const std::string _type;
	bool _isSigned;
	const int _signGrade;
	const int _execGrade;

  public:
	AForm(void);
	AForm(AForm const &copy);
	virtual AForm &operator=(AForm const &rhs);
	virtual ~AForm(void);
	AForm(std::string name, int sign, int exec, std::string type);
	std::string getName(void) const;
	bool getSignStatus(void) const;
	int getSignGrade(void) const;
	int getExecGrade(void) const;
	std::string getType(void) const;
	void beSigned(Bureaucrat const &worker);
	virtual void action() const = 0;
	virtual void execute(Bureaucrat const &executor) const = 0;
	/*******************************************EXCEPTION-CLASSES*******************************************/
	class GradeTooHighException : public std::exception
	{
		public:
		virtual const char *what() const throw()
		{
			return ("grade is too high");
		}
	};
	class GradeTooLowException : public std::exception
	{
		public:
		virtual const char *what() const throw()
		{
			return ("grade is too low");
		}
	};
    class FormNotSignedException : public std::exception
	{
		public:
		virtual const char *what() const throw()
		{
			return ("the form is not signed");
		}
	};
};

std::ostream &operator<<(std::ostream &output, const AForm &form);

#endif