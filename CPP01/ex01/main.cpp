/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykissiko <ykissiko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/02 16:23:05 by ykissiko          #+#    #+#             */
/*   Updated: 2023/12/03 19:36:53 by ykissiko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./Zombie.hpp"

int main()
{
    Zombie *horde = zombieHorde(10, "dodo");

    for (int i = 0; i < 10; i++)
        horde[i].announce();
    
    delete [] horde;

    return (0);
}
