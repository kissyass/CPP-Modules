/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykissiko <ykissiko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 16:40:39 by ykissiko          #+#    #+#             */
/*   Updated: 2023/12/06 17:23:50 by ykissiko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP

#include "ClapTrap.hpp"

class ScavTrap : public ClapTrap
{
    public:
        ScavTrap(void);
        ScavTrap(ScavTrap const &copy);
        ScavTrap & operator=(ScavTrap const &rhs);
        ~ScavTrap(void);
        ScavTrap(std::string name);
        void attack(const std::string & target);
        void guardGate(void);
};

#endif