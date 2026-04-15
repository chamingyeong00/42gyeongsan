/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: micha <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/19 16:05:44 by micha             #+#    #+#             */
/*   Updated: 2026/01/19 16:05:50 by micha            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main(void)
{
	Zombie *newZombie1;
	
	newZombie1 = newZombie("New Zombie");
	newZombie1->announce();
	randomChump("Random Zombie");
	delete newZombie1;
	return (0);
}
