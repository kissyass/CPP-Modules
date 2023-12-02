/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykissiko <ykissiko@student.42istanbul.com  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/02 17:12:53 by ykissiko          #+#    #+#             */
/*   Updated: 2023/12/02 17:12:54 by ykissiko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

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