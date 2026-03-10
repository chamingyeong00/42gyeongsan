/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: micha <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/19 16:10:01 by micha             #+#    #+#             */
/*   Updated: 2026/01/19 16:10:03 by micha            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int main (void)
{
	Harl harl;

	std::cout << std::endl << "DEBUG" << std::endl;
	harl.complain("DEBUG");
	std::cout << std::endl << "INFO" << std::endl;;
	harl.complain("INFO");
	std::cout << std::endl << "WARNING" << std::endl;
	harl.complain("WARNING");
	std::cout << std::endl << "ERROR" << std::endl;
	harl.complain("ERROR");
	std::cout << std::endl << "No valid" << std::endl;
	harl.complain("ALARM");
	return (0);
}
