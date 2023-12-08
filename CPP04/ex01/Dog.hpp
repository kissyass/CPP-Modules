/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykissiko <ykissiko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 15:20:27 by ykissiko          #+#    #+#             */
/*   Updated: 2023/12/08 16:35:12 by ykissiko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef DOG_HPP
#define DOG_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class Dog : public Animal
{
    private:
        Brain *brain;
    public:
        Dog(void);
        Dog(Dog const &copy);
        Dog & operator=(Dog const &rhs);
        ~Dog(void);
        void makeSound(void) const;
        std::string getType(void) const;
        std::string getIdea(int i) const;   
};

#endif