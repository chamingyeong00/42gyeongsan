/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: micha <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/19 16:38:55 by micha             #+#    #+#             */
/*   Updated: 2026/01/19 16:38:56 by micha            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_H
# define CONTACT_H
# include <string>
# include <ctime>

class Contact
{
	private:
		std::string _Last_name;
		std::string _First_name;
		std::string _Nick_name;
		std::string _Phone_number;
		std::string _Darkest_secret;
		time_t 		_Created;

	public:
		Contact();
		~Contact();
		Contact(std::string first_name, std::string last_name, std::string nick_name,
			std::string phone_number, std::string darkest_secret);
		
		std::string	getLastName() const;
		std::string	getFirst_name() const;
		std::string	getNick_name() const;
		std::string	getPhone_number() const;
		std::string	getDarkest_secret() const;
		time_t		getCreated() const;
};
#endif
