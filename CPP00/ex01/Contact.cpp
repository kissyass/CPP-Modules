/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykissiko <ykissiko@student.42istanbul.com  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 17:08:04 by ykissiko          #+#    #+#             */
/*   Updated: 2023/11/19 17:08:06 by ykissiko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "phonebook.h"

Contact::Contact()
{
}

Contact::~Contact()
{
}

std::string Contact::get_firstname(void)
{
	return (this->_first_name);
}
std::string Contact::get_lastname(void)
{
	return (this->_last_name);
}
std::string Contact::get_nickname(void)
{
	return (this->_nickname);
}
std::string Contact::get_phone_num(void)
{
	return (this->_phone);
}
std::string Contact::get_secret(void)
{
	return (this->_secret);
}
void Contact::set_firstname(std::string str)
{
	this->_first_name = str;
}
void Contact::set_lastname(std::string str)
{
	this->_last_name = str;
}
void Contact::set_nickname(std::string str)
{
	this->_nickname = str;
}
void Contact::set_phone_num(std::string str)
{
	this->_phone = str;
}
void Contact::set_secret(std::string str)
{
	this->_secret = str;
}
