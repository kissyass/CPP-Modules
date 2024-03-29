/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykissiko <ykissiko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/02 14:39:18 by ykissiko          #+#    #+#             */
/*   Updated: 2023/12/03 19:35:26 by ykissiko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./Zombie.hpp"

int main()
{
    Zombie z1;
    Zombie z2("Second zombie");
    Zombie *heap = newZombie("Heaped zombie");
    randomChump("Chump zombie");

    z1.announce();
    z2.announce();
    heap->announce();

    delete heap;

    return (0);
}