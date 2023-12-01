/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykissiko <ykissiko@student.42istanbul.com  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 13:41:40 by ykissiko          #+#    #+#             */
/*   Updated: 2023/11/19 13:41:46 by ykissiko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_H
# define PHONEBOOK_H

# include <iostream>

class Contact
{
  private:
	std::string _first_name;
	std::string _last_name;
	std::string _nickname;
	std::string _phone;
	std::string _secret;

  public:
	Contact(void);
	~Contact(void);
	std::string get_firstname(void);
	std::string get_lastname(void);
	std::string get_nickname(void);
	std::string get_phone_num(void);
	std::string get_secret(void);
	void set_firstname(std::string str);
	void set_lastname(std::string str);
	void set_nickname(std::string str);
	void set_phone_num(std::string str);
	void set_secret(std::string str);
};

class PhoneBook
{
  private:
	Contact _contacts[8];
	int _index;
	int _max;

  public:
	PhoneBook(void);
	~PhoneBook(void);
	void add(void);
	void search(void);
	void print(Contact contact);
	std::string format_name(std::string name);
};
#endif
