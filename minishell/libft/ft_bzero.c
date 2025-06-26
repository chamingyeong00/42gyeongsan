/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chankim <chankim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/26 15:37:27 by chankim           #+#    #+#             */
/*   Updated: 2025/06/26 15:38:25 by chankim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
	DESCRIPTION :
	The function ft_bzero erases data in the n bytes of memory starting
	at location s by writing '\0's.

	RETURN VALUE :
	None.
*/

void	ft_bzero(void *s, size_t n)
{
	unsigned char	*p;

	p = (unsigned char *)s;
	while (n != 0)
	{
		*p = '\0';
		p++;
		n--;
	}
}
