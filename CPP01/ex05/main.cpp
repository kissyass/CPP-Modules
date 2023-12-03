/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykissiko <ykissiko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/02 17:12:53 by ykissiko          #+#    #+#             */
/*   Updated: 2023/12/03 19:46:28 by ykissiko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./Harl.hpp"

int main()
{
    Harl harl;

    std::cout << "Debugging:" << std::endl;
    harl.complain("DEBUG");
    std::cout << "Informing:" << std::endl;
    harl.complain("INFO");
    std::cout << "Warning:" << std::endl;
    harl.complain("WARNING");
    std::cout << "Erroring:" << std::endl;
    harl.complain("ERROR");
    
    return(0);
}