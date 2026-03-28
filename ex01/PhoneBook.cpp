/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elmondo <elmondo@student.42firenze.it>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/27 14:38:09 by elmondo           #+#    #+#             */
/*   Updated: 2026/03/28 11:52:56 by elmondo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

PhoneBook::PhoneBook()
{
	this->_contactCount = 0;
	this->_oldestIndex = 0;
}

std::string PhoneBook::_formatColumn(std::string str) const
{
	if(str.length() > 10)
		return str.substr(0, 9) + ".";
	else
		return str;
}

void PhoneBook::addContact(Contact contact)
{
	if(this->_contactCount < 8)
	{
		this->_contacts[this->_contactCount] = contact;
		this->_contactCount++;
	}
	else
	{
		this->_contacts[this->_oldestIndex] = contact;
		this->_oldestIndex =(this->_oldestIndex + 1) % 8; 
	}
}

void PhoneBook::displayContacts() const
{
	std::cout << std::endl;
	std::cout << "|" << std::setw(10) << "Index" << "|";
	std::cout << std::setw(10) << "First Name" << "|";
	std::cout << std::setw(10) << "Last Name" << "|";
	std::cout << std::setw(10) << "NickName" << "|" << std::endl;
	std::cout << "|----------|----------|----------|----------|" << std::endl;
	
	for (int i = 0; i < this->_contactCount; i++)
	{
		std::cout << "|" << std::setw(10) << (i + 1) << "|";
		std::cout << std::setw(10) << _formatColumn(this->_contacts[i].getFirstName()) << "|";
		std::cout << std::setw(10) << _formatColumn(this->_contacts[i].getLastName()) << "|";
		std::cout << std::setw(10) << _formatColumn(this->_contacts[i].getNickName()) << "|" << std:: endl;
	}
	std::cout << std::endl;
}

void PhoneBook::displayContactsByIndex(int index) const
{
	if(index < 1 || index > this->_contactCount)
	{
		std::cout << "Invalid Contact!" << std::endl;
		return;
	}
	std::cout << std::endl;
	std::cout << "First Name: " << this->_contacts[index - 1].getFirstName() << std::endl;
	std::cout << "Last Name: " << this->_contacts[index - 1].getLastName() << std::endl;
	std::cout << "Nickname: " << this->_contacts[index - 1].getNickName() << std::endl;
	std::cout << "Phone Number: " << this->_contacts[index - 1].getPhoneNumber() << std::endl;
	std::cout << "Darkest Secret: " << this->_contacts[index - 1].getDarkestSecret() << std::endl;
}

int PhoneBook::getContactCount() const
{
	return this->_contactCount;
}