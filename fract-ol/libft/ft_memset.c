/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memset.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: micha <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 13:47:43 by micha             #+#    #+#             */
/*   Updated: 2024/10/01 13:47:44 by micha            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *dest, int ch, size_t count)
{
	unsigned char		*ptr;
	size_t				i;

	i = 0;
	ptr = (unsigned char *)dest;
	while (count > 0)
	{
		ptr[i] = (unsigned char)ch;
		count--;
		i++;
	}
	return (dest);
}
