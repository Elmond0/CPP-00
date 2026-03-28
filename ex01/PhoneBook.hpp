/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elmondo <elmondo@student.42firenze.it>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/27 14:38:12 by elmondo           #+#    #+#             */
/*   Updated: 2026/03/27 14:44:56 by elmondo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include "Contact.hpp"

class PhoneBook
{
	private:
		Contact _contacts[8];
		int _contactCount;
		int _oldestIndex;
		std::string _formatColumn(std::string str) const;

	public:
		PhoneBook();
		void addContact(Contact contact);
		void displayContacts() const;
		void displayContactsByIndex(int index) const;
		int getContactCount() const;
};

#endif