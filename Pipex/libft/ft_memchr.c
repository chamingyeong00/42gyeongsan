/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: micha <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 20:40:19 by micha             #+#    #+#             */
/*   Updated: 2024/10/01 20:40:20 by micha            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *ptr, int ch, size_t count)
{
	size_t				i;
	unsigned char		*ptr1;

	i = 0;
	ptr1 = (unsigned char *)ptr;
	while (i < count)
	{
		if (ptr1[i] == (unsigned char)ch)
			return (&ptr1[i]);
		i++;
	}
	return (0);
}
