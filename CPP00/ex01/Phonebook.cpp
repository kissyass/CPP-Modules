/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykissiko <ykissiko@student.42istanbul.com  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 13:42:18 by ykissiko          #+#    #+#             */
/*   Updated: 2023/11/19 13:42:20 by ykissiko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "phonebook.h"

PhoneBook :: PhoneBook()
{
    std::cout << "_____Welcome to the Crappy Awesome PhoneBook_____\n";
    this->_index = 0;
    this->_max = 0;
}

PhoneBook :: ~PhoneBook()
{
    std::cout << "Bye bye ~\n";
}

void PhoneBook :: add()
{
    std::string str;

    if (this->_index > 7)
    {
        this->_index = 0;
        std::cout << "Information about contacts will be rewritten\n";
    }
    while (str == "" && !std::cin.eof())
    {
        std::cout << "Enter first name: ";
        std::getline(std::cin, str);
    }
    this->_contacts[this->_index].set_firstname(str);
    str = "";
    while (str == "" && !std::cin.eof())
    {
        std::cout << "Enter last name: ";
        std::getline(std::cin, str);
    }
    this->_contacts[this->_index].set_lastname(str);
    str = "";
    while (str == "" && !std::cin.eof())
    {
        std::cout << "Enter nickname: ";
        std::getline(std::cin, str);
    }
    this->_contacts[this->_index].set_nickname(str);
    str = "";
    while (str == "" && !std::cin.eof())
    {
        std::cout << "Enter phone number: ";
        std::getline(std::cin, str);
    }
    this->_contacts[this->_index].set_phone_num(str);
    str = "";
    while (str == "" && !std::cin.eof())
    {
        std::cout << "Enter the darkest secret: ";
        std::getline(std::cin, str);
    }
    this->_contacts[this->_index].set_secret(str);
    std::cout << "~~Contact is successfully added~~\n";
    this->_index++;
    if (this->_index <= 8 && this->_max < 8)
        this->_max++;
}

void PhoneBook :: search()
{
    int index;

    index = -1;
    if (this->_max == 0)
    {
        std::cout << "No contacts were added to search them. Add contacts first\n";
        return ;
    }
    std::cout << "\n ------------------------------------------- \n";
    std::cout << "|     Index|First Name| Last Name|  Nickname|\n";
    std::cout << " ------------------------------------------- \n";
    while (++index < this->_max)
    {
        std::cout << "|         " << index + 1;
        std::cout << "|" << this->format_name(this->_contacts[index].get_firstname());
        std::cout << "|" << this->format_name(this->_contacts[index].get_lastname());
        std::cout << "|" << this->format_name(this->_contacts[index].get_nickname()) << "|\n";
    }
    std::cout << " ------------------------------------------- \n";
    std::string str = "";
    while (str == "" && !std::cin.eof())
    {
        std::cout << "Enter the index: ";
        std::getline(std::cin, str);
        if (str.length() > 1 || !(str[0] >= '1' && str[0] <= this->_max + '0'))
        {
            std::cout << "Invalid index! Try again!\n";
            str = "";
        }
        else
            this->print(this->_contacts[str[0] - '0' - 1]);
    }
}

std::string PhoneBook :: format_name(std::string str)
{
    std::string name;

    if (str.length() > 10)
    {
        str.resize(10);
        str[9] = '.';
        return (str);
    }
    else
    {
        unsigned long i = -1;
        while (++i < 10 - str.length())
            name.append(" ");
        name += str;
    }
    return (name);
}

void PhoneBook :: print(Contact contact)
{
    std::cout << "\nAll information that we have:\n\n";
    std::cout << "First Name: " << contact.get_firstname() << std::endl;
    std::cout << "Last Name: " << contact.get_lastname() << std::endl;
    std::cout << "Nickname: " << contact.get_nickname() << std::endl;
    std::cout << "Phone Number: " << contact.get_phone_num() << std::endl;
    std::cout << "Darkest secret: " << contact.get_secret() << std::endl << std::endl;
}
