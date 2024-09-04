/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_advanced_sort_string_tab.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: micha <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/31 18:11:07 by micha             #+#    #+#             */
/*   Updated: 2024/08/31 18:11:08 by micha            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_swap(char **s1, char **s2)
{
	char	*tmp;

	tmp = *s1;
	*s1 = *s2;
	*s2 = tmp;
}

void	ft_advanced_sort_string_tab(char **tab, int (*cmp)(char *, char *))
{
	int	i;
	int	flag;

	while (1)
	{
		i = 0;
		flag = 0;
		while (tab[i + 1])
		{
			if ((*cmp)(tab[i], tab[i + 1]) > 0)
			{
				ft_swap(&tab[i], &tab[i + 1]);
				flag = 1;
			}
			i++;
		}
		if (!flag)
			break ;
	}
}
