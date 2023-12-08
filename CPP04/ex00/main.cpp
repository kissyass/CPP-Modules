/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykissiko <ykissiko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 14:41:30 by ykissiko          #+#    #+#             */
/*   Updated: 2023/12/08 17:45:06 by ykissiko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main()
{
    {
        const Animal* animal = new Animal();
        const Animal* dog = new Dog();
        const Animal* cat = new Cat();
        std::cout << "----------------------------------------------" << std::endl;
        
        std::cout << "Type of the dog object: " << dog->getType() << std::endl;
        std::cout << "Type of the cat object: " << cat->getType() << std::endl;
        std::cout << "Type of the animal object: " << animal->getType() << std::endl;
        
        std::cout << "----------------------------------------------" << std::endl;

        std::cout << "Dog makes sound: ";    
        dog->makeSound();
        std::cout << "Cat makes sound: ";
        cat->makeSound(); //will output the cat sound!
        std::cout << "Animal makes sound: ";
        animal->makeSound();

        std::cout << "----------------------------------------------" << std::endl;
        
        std::cout << "Dog:" << std::endl;
        delete dog;
        std::cout << "Cat:" << std::endl;
        delete cat;
        std::cout << "Animal:" << std::endl;
        delete animal;
    }
    std::cout << "----------------------------------------------" << std::endl;
    std::cout << "----------------------------------------------" << std::endl;
    {
        const WrongAnimal* wanimal = new WrongAnimal();
        const WrongAnimal* wcat = new WrongCat();

        std::cout << "----------------------------------------------" << std::endl;
        
        std::cout << "Type of the wrong cat object: " << wcat->getType() << std::endl;
        std::cout << "Type of the wrong animal object: " << wanimal->getType() << std::endl;
        
        std::cout << "----------------------------------------------" << std::endl;

        std::cout << "Wrong cat makes sound: ";
        wcat->makeSound();
        std::cout << "Wrong animal makes sound: ";
        wanimal->makeSound();

        std::cout << "----------------------------------------------" << std::endl;

        std::cout << "Wrong cat:" << std::endl;
        delete wcat;
        std::cout << "Wrong animal:" << std::endl;
        delete wanimal;
    }    

    return 0;
}