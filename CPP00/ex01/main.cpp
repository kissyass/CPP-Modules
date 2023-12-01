/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykissiko <ykissiko@student.42istanbul.com  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 13:42:50 by ykissiko          #+#    #+#             */
/*   Updated: 2023/11/19 13:42:52 by ykissiko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "phonebook.h"

int	main(void)
{
	PhoneBook phb;
	std ::string str;

	while (str != "EXIT")
	{
		std::cout << "Enter a command: ";
		std::getline(std::cin, str);
		if (str == "ADD")
			phb.add();
		else if (str == "SEARCH")
			phb.search();
		if (std::cin.eof())
		{
			std::cout << std::endl;
			return (0);
		}
	}
	return (0);
}