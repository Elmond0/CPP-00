/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elmondo <elmondo@student.42firenze.it>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/27 12:20:19 by elmondo           #+#    #+#             */
/*   Updated: 2026/03/28 11:56:50 by elmondo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cstdlib>
#include "Contact.hpp"
#include "PhoneBook.hpp"

std::string getInput(std::string prompt)
{
	std::string input;
	
	while(1)
	{
		std::cout << prompt;
		if(!std::getline(std::cin, input))
		{
			std::cout << std::endl;
			std::cout << "Leaving the PhoneBook" << std::endl;
			exit(0);
		}
		if(!input.empty())
			return input;
		std::cout << "Field cannot be empty!" << std::endl;
	}
}

void handleAdd(PhoneBook &PhoneBook)
{
	Contact Contact;

	std::cout << "--- Adding new contact ---" << std::endl;
	Contact.setFirstName(getInput("First Name: "));
	Contact.setLastName(getInput("Last Name: "));
	Contact.setNickName(getInput("Nickname: "));
	Contact.setPhoneNumber(getInput("Phone Number: "));
	Contact.setDarkestSecret(getInput("Darkest Secret: "));

	PhoneBook.addContact(Contact);
	std::cout << "Contact added successfully!" << std::endl;
}

void handleSearch(PhoneBook &PhoneBook)
{
	std::string input;
	int index;

	if(PhoneBook.getContactCount() == 0)
	{
		std::cout << "PhoneBook is empty!" << std::endl;
		return;
	}
	PhoneBook.displayContacts();
	std::cout << "Enter index to view details: ";
	if(!std::getline(std::cin, input))
	{
		std::cout << std::endl;
		exit(0);
	}
	index = std::atoi(input.c_str());
	if(input.empty() || (index == 0 && input != "0"))
	{
		std::cout << "Invalid input!" << std::endl;
		return;
	}
	PhoneBook.displayContactsByIndex(index);
}

int main()
{
	PhoneBook PhoneBook;
	std::string command;
	
	std::cout << "Welcome to my PhoneBook!" << std::endl;
	std::cout << "Commands: ADD, SEARCH, EXIT" << std::endl;
	
	while(1)
	{
		std::cout << "> ";
		if(!std::getline(std::cin, command))
		{
			std::cout << std::endl;
			break;
		}
		if(command == "ADD")
			handleAdd(PhoneBook);
		else if(command == "SEARCH")
			handleSearch(PhoneBook);
		else if(command == "EXIT")
			break;
	}
	std::cout << "Leaving the PhoneBook" << std::endl;
	return 0;
}