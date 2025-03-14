/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: micha <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/12 15:15:15 by micha             #+#    #+#             */
/*   Updated: 2024/10/12 15:15:17 by micha            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	unsigned int	len;
	unsigned int	i;

	i = 0;
	if (!s || !f)
		return ;
	len = ft_strlen(s);
	while (i < len)
	{
		(*f)(i, &s[i]);
		i++;
	}
}
