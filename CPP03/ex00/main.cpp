/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykissiko <ykissiko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 16:28:17 by ykissiko          #+#    #+#             */
/*   Updated: 2023/12/06 17:49:15 by ykissiko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int main()
{
    ClapTrap carry("Carry");
    ClapTrap jim(carry);
    ClapTrap tom;

    carry.attack("Tom");
    jim.attack("Carry");
    carry.takeDamage(10);
    carry.takeDamage(10);
    tom.takeDamage(0);
    carry.attack("Jim");
    carry.beRepaired(10);
    carry.attack("Jim");
    carry.beRepaired(10);
    carry.attack("Jim");
    carry.attack("Jim");
    carry.attack("Jim");
    carry.attack("Jim");
    carry.attack("Jim");
    carry.attack("Jim");
    carry.attack("Jim");
    carry.attack("Jim");
    carry.attack("Jim");


    return 0;
}