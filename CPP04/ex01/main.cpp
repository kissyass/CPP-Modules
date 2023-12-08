/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykissiko <ykissiko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 14:41:30 by ykissiko          #+#    #+#             */
/*   Updated: 2023/12/08 17:41:56 by ykissiko         ###   ########.fr       */
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
    const Animal* animals[10];
    const Animal* dog = new Dog();
    const Animal* cat = new Cat();
    Cat kitty; 
    std::cout << "----------------------------------------------" << std::endl;

    for (int i = 0; i < 5; i ++)
        animals[i] = new Cat();
    for (int i = 5; i < 10; i++)
        animals[i] = new Dog();

    std::cout << "----------------------------------------------" << std::endl;
    
    std::cout << "Type of the dog object: " << dog->getType() << std::endl;
    std::cout << "Type of the cat object: " << cat->getType() << std::endl;
    
    std::cout << "----------------------------------------------" << std::endl;

    std::cout << "Dog makes sound: ";    
    dog->makeSound();
    std::cout << "Cat makes sound: ";
    cat->makeSound();

    std::cout << "----------------------------------------------" << std::endl;

    std::cout << "Cat ideas:" << std::endl;

    for (int i = 0; i < 100; i++)
        std::cout << kitty.getIdea(i) << std::endl;

    std::cout << "----------------------------------------------" << std::endl;
    
    std::cout << "Dog:" << std::endl;
    delete dog;
    std::cout << "Cat:" << std::endl;
    delete cat;
    std::cout << "Animals:" << std::endl;
    for (int i = 0; i < 10; i++)
        delete animals[i];

    return 0;
}