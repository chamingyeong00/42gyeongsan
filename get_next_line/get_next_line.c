/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: micha <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 00:26:07 by micha             #+#    #+#             */
/*   Updated: 2025/01/10 00:26:10 by micha            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*get_buffer(int fd, char *backup)
{
	int			len;
	char		*buffer;

	buffer = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buffer)
		return (0);
	buffer[0] = '\0';
	while (!ft_strchr(backup, '\n'))
	{
		len = read(fd, buffer, BUFFER_SIZE);
		if (len == 0)
			break ;
		if (len < 0)
		{
			free(buffer);
			return (0);
		}
		buffer[len] = '\0';
		backup = ft_strjoin(backup, buffer);
	}
	free(buffer);
	return (backup);
}

static char	*get_one_line(char **backup)
{
	char	*line;
	char	*temp;
	int		i;

	i = 0;
	while ((*backup)[i] != 0 && (*backup)[i] != '\n')
		i++;
	if ((*backup)[i] == '\n')
		i++;
	line = ft_substr(*backup, 0, i);
	temp = ft_strdup(*backup + i);
	free(*backup);
	*backup = temp;
	return (line);
}

char	*get_next_line(int fd)
{
	static char	*backup;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	backup = get_buffer(fd, backup);
	if (!backup || !*backup)
	{
		free(backup);
		backup = NULL;
		return (NULL);
	}
	return (get_one_line(&backup));
}
