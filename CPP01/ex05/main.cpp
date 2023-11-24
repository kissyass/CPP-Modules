#include "Harl.h"

int main()
{
    Harl harl;

    std::cout << "Debugging:\n";
    harl.complain("DEBUG");
    std::cout << "Informing:\n";
    harl.complain("INFO");
    std::cout << "Warning:\n";
    harl.complain("WARNING");
    std::cout << "Erroring:\n";
    harl.complain("ERROR");
    std::cout << "Sending wrong level:\n";
    harl.complain("WRONG");
    
    return(0);
}