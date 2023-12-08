/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykissiko <ykissiko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 14:41:34 by ykissiko          #+#    #+#             */
/*   Updated: 2023/12/08 18:00:42 by ykissiko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <iostream>

class Animal
{
    protected:
        std::string _type;
    public:
        Animal(void);
        Animal(Animal const &copy);
        Animal & operator=(Animal const &rhs);
        virtual ~Animal(void);
        virtual void makeSound(void) const = 0;
        std::string getType(void) const;
};

#endif