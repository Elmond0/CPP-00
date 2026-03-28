/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elmondo <elmondo@student.42firenze.it>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/27 14:01:21 by elmondo           #+#    #+#             */
/*   Updated: 2026/03/27 14:37:18 by elmondo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

Contact::Contact(){}

void Contact::setFirstName(std::string firstName)
{
	this->_firstName = firstName;
}

void Contact::setLastName(std::string lastName)
{
	this->_lastName = lastName;
}

void Contact::setNickName(std::string nickName)
{
	this->_nickName = nickName;
}

void Contact::setPhoneNumber(std::string phoneNumber)
{
	this->_phoneNumber = phoneNumber;
}

void Contact::setDarkestSecret(std::string darkestSecret)
{
	this->_darkestSecret = darkestSecret;
}

std::string Contact::getFirstName() const
{
	return this->_firstName;
}

std::string Contact::getLastName() const
{
	return this->_lastName;
}

std::string Contact::getNickName() const
{
	return this->_nickName;
}

std::string Contact::getPhoneNumber() const
{
	return this->_phoneNumber;
}

std::string Contact::getDarkestSecret() const
{
	return this->_darkestSecret;
}

bool Contact::isEmpty() const
{
	return(_firstName.empty() && _lastName.empty() && _nickName.empty() &&_phoneNumber.empty() && _darkestSecret.empty());
}