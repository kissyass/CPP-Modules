/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykissiko <ykissiko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 16:28:17 by ykissiko          #+#    #+#             */
/*   Updated: 2023/12/07 12:15:43 by ykissiko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int main()
{
    ClapTrap carry("Carry");
    ClapTrap jim(carry);
    ClapTrap tom;

    carry.attack("Tom");
    carry.attack("Tom");
    carry.attack("Tom");
    carry.attack("Tom");
    carry.attack("Tom");
    carry.beRepaired(10);
    carry.beRepaired(10);
    carry.beRepaired(10);
    carry.beRepaired(10);
    carry.beRepaired(10);
    carry.beRepaired(10);
    carry.attack("Tom");
    carry.attack("Tom");
    carry.attack("Tom");
    std::cout << "----------------------------------------------------------------------------" << std::endl;
    jim.attack("Carry");
    jim.takeDamage(10);
    jim.takeDamage(10);
    jim.attack("Carry");
    jim.attack("Carry");
    jim.beRepaired(10);
    std::cout << "----------------------------------------------------------------------------" << std::endl;
    tom.attack("Carry");
    tom.attack("Carry");
    tom.takeDamage(5);
    tom.beRepaired(5);
    tom.beRepaired(5);


    return 0;
}