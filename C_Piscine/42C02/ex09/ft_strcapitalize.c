/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: micha <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/14 10:44:32 by micha             #+#    #+#             */
/*   Updated: 2024/08/15 16:39:21 by micha            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	is_char_upper(char *str, int i)
{
	char	ch;

	ch = str[i - 1];
	if ((ch >= 'a' && ch <= 'z')
		|| (ch >= 'A' && ch <= 'Z')
		|| (ch >= '0' && ch <= '9'))
	{
		return (1);
	}
	else
		return (0);
}

int	is_char_low(char *str, int i)
{
	char	ch;

	ch = str[i - 1];
	if ((ch >= 'a' && ch <= 'z')
		|| (ch >= 'A' && ch <= 'Z')
		|| (ch >= '0' && ch <= '9'))
	{
		return (0);
	}
	else
		return (1);
}

char	*ft_strcapitalize(char *str)
{
	int	i;

	if (str[0] >= 'a' && str[0] <= 'z')
		str[0] -= 32;
	i = 1;
	while (str[i] != '\0')
	{
		if (str[i] >= 'A' && str[i] <= 'Z')
		{
			if (is_char_upper(str, i))
				str[i] += 32;
		}
		else if (str[i] >= 'a' && str[i] <= 'z')
		{
			if (is_char_low(str, i))
				str[i] -= 32;
		}
		i++;
	}
	return (str);
}
