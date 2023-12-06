/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykissiko <ykissiko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 16:28:17 by ykissiko          #+#    #+#             */
/*   Updated: 2023/12/06 19:32:59 by ykissiko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./ClapTrap.hpp"
#include "./ScavTrap.hpp"

int main()
{
    ClapTrap carry("Carry");
    ScavTrap tom("Tom");

    carry.attack("Tom");
    tom.takeDamage(0);
    tom.beRepaired(100);
    tom.attack("Jim");
    carry.takeDamage(20);
    carry.attack("Tom");
    carry.beRepaired(100);
    carry.attack("Tom");
    carry.attack("Tom");
    tom.guardGate();

    return 0;
}