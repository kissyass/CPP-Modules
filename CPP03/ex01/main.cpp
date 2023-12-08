/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykissiko <ykissiko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 16:28:17 by ykissiko          #+#    #+#             */
/*   Updated: 2023/12/07 12:23:15 by ykissiko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./ClapTrap.hpp"
#include "./ScavTrap.hpp"

int main()
{
    ClapTrap carry("Carry");
    ScavTrap tom("Tom");
    ScavTrap jerry(tom);

    carry.attack("Tom");
    tom.attack("Jim");
    tom.attack("Jim");
    tom.attack("Jim");
    tom.attack("Jim");
    tom.takeDamage(10);
    tom.takeDamage(10);
    tom.takeDamage(10);
    tom.takeDamage(10);
    tom.takeDamage(10);
    tom.takeDamage(10);
    tom.takeDamage(10);
    tom.beRepaired(5);
    tom.beRepaired(5);
    tom.beRepaired(5);
    tom.beRepaired(5);
    tom.beRepaired(5);
    tom.beRepaired(5);
    tom.beRepaired(5);
    tom.guardGate();
    std::cout << "----------------------------------------------------------------------------" << std::endl;
    jerry.attack("Jim");
    jerry.attack("Jim");
    jerry.attack("Jim");
    jerry.takeDamage(20);
    jerry.takeDamage(20);
    jerry.takeDamage(20);
    jerry.attack("Tom");
    jerry.beRepaired(100);
    jerry.beRepaired(100);
    jerry.takeDamage(20);
    jerry.takeDamage(200);
    jerry.attack("Tom");

    return 0;
}