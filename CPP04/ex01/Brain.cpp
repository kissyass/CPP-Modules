/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykissiko <ykissiko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 16:12:23 by ykissiko          #+#    #+#             */
/*   Updated: 2023/12/08 16:19:01 by ykissiko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain :: Brain(void)
{
    std::cout << "Brain constructor is called" << std::endl;

    for (int i = 0; i < 100; i++)
        this->ideas[i] = "Bright idea number " + std::to_string(i + 1);
}

Brain :: Brain(Brain const &copy)
{
    std::cout << "Copy constructor from Brain class is called" << std::endl;

    *this = copy;
}

Brain & Brain :: operator=(Brain const &rhs)
{
    std::cout << "Copy operator from Brain class is called" << std::endl;

    if (this != &rhs)
    {
        for (int i = 0; i < 100; i ++)
            this->ideas[i] = rhs.ideas[i];
    }

    return *this;
}

Brain :: ~Brain(void)
{
    std::cout << "Destructor from Brain class is called" << std::endl;
}

std::string Brain :: getIdea(int i) const
{
    return this->ideas[i];
}