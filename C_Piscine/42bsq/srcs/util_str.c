/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util_str.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chsung <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 22:50:47 by chsung            #+#    #+#             */
/*   Updated: 2024/08/26 22:50:48 by chsung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "util_str.h"

#define INIT_SIZE 4

t_str	*bsq_str_new(void)
{
	t_str	*new;

	new = (t_str *)malloc(sizeof(t_str));
	new->str = malloc(INIT_SIZE * sizeof(char));
	new->size = INIT_SIZE;
	new->last = -1;
	new->meet_nl = 0;
	return (new);
}

void	bsq_str_free(t_str *str)
{
	free(str->str);
	free(str);
}

void	bsq_str_extand(t_str *s)
{
	int		i;
	char	*src;

	i = -1;
	src = s->str;
	s->size *= 2;
	s->str = malloc(s->size * sizeof(char));
	while (++i <= s->last)
		s->str[i] = src[i];
	free(src);
}

void	bsq_str_add(t_str *s, char c)
{
	if (s->last == s->size - 1)
		bsq_str_extand(s);
	s->last++;
	s->str[s->last] = c;
}

t_str	*bsq_read_line(int fd)
{
	int		i;
	char	c;
	t_str	*line;

	line = bsq_str_new();
	i = 0;
	while (read(fd, &c, 1))
	{
		if (c == '\n')
		{
			line->meet_nl = 1;
			break ;
		}
		bsq_str_add(line, c);
		i++;
	}
	return (line);
}
