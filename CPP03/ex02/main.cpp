/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykissiko <ykissiko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 16:28:17 by ykissiko          #+#    #+#             */
/*   Updated: 2023/12/06 19:37:19 by ykissiko         ###   ########.fr       */
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

    carry.attack("Tom");
    tom.takeDamage(0);
    tom.attack("Jim");
    carry.takeDamage(20);
    carry.attack("Tom");
    carry.beRepaired(100);
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