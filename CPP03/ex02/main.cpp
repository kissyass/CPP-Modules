/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykissiko <ykissiko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 16:28:17 by ykissiko          #+#    #+#             */
/*   Updated: 2023/12/07 12:27:34 by ykissiko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./ClapTrap.hpp"
#include "./ScavTrap.hpp"
#include "./FragTrap.hpp"

int main()
{
    ClapTrap carry("Carry");
    ScavTrap tom("Tom");
    FragTrap jim("Jim");
    FragTrap jerry(jim);
    std::cout << "----------------------------------------------------------------------------" << std::endl;
    jim.attack("Tom");
    jim.attack("Tom");
    jim.attack("Tom");
    jim.attack("Tom");
    jim.attack("Tom");
    jim.takeDamage(10);
    jim.beRepaired(20);
    jim.takeDamage(100);
    jim.attack("Tom");
    jim.attack("Tom");
    jim.beRepaired(20);
    std::cout << "----------------------------------------------------------------------------" << std::endl;
    jerry.takeDamage(20);
    jerry.attack("Tom");
    jerry.beRepaired(100);
    jerry.highFivesGuys();
    std::cout << "----------------------------------------------------------------------------" << std::endl;
    carry.attack("Tom");
    carry.attack("Tom");
    tom.guardGate();
    jim.attack("Tom");
    jim.takeDamage(20);
    jim.takeDamage(20);
    jim.takeDamage(20);
    jim.takeDamage(20);
    jim.takeDamage(20);
    jim.takeDamage(20);
    jim.attack("Tom");
    jim.beRepaired(10);
    jim.attack("Tom");
    jim.highFivesGuys();

    return 0;
}