/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykissiko <ykissiko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 14:41:30 by ykissiko          #+#    #+#             */
/*   Updated: 2023/12/08 18:03:10 by ykissiko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
#include "Brain.hpp"

int main()
{
    const Animal* dog = new Dog();
    const Cat* cat = new Cat();
    // Animal animal;
    // const Animal *animal = new Animal();

    std::cout << "----------------------------------------------" << std::endl;
    
    std::cout << "Type of the dog object: " << dog->getType() << std::endl;
    std::cout << "Type of the cat object: " << cat->getType() << std::endl;
    
    std::cout << "----------------------------------------------" << std::endl;

    std::cout << "Dog makes sound: ";    
    dog->makeSound();
    std::cout << "Cat makes sound: ";
    cat->makeSound();

    std::cout << "----------------------------------------------" << std::endl;
    
    std::cout << "Dog:" << std::endl;
    delete dog;
    std::cout << "Cat:" << std::endl;
    delete cat;

    return 0;
}