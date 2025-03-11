/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: micha <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 20:09:18 by micha             #+#    #+#             */
/*   Updated: 2025/03/11 20:09:20 by micha            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipe.h"

char	**path_maker(char *envp[])
{
	int	i;

	i = 0;
	while (envp[i])
	{
		if (ft_strnstr(envp[i], "PATH=", 5))
			return (ft_split2(envp[i] + 5, ':'));
		i++;
	}
	return (0);
}

char	*check_order(char **path, char *cmd)
{
	int		i;
	char	*find;

	if (access(cmd, X_OK) == 0)
		return (cmd);
	i = 0;
	while (path[i])
	{
		find = ft_strjoin(path[i], cmd);
		if (access(find, X_OK) == 0)
			return (find);
		free(find);
		i++;
	}
	return (0);
}

void	first_child(t_data *all, int *fd, char *argv[], char *envp[])
{
	all->infile = open(argv[1], O_RDONLY, 0644);
	if (all->infile == -1)
		perror("file open error");
	all->order1 = check_order(all->path, all->cmd1[0]);
	close(fd[0]);
	if (dup2(all->infile, 0) == -1)
		just_error("dup error");
	if (dup2(fd[1], 1) == -1)
		just_error("dup error");
	close(fd[1]);
	close(all->infile);
	if (execve(all->order1, all->cmd1, envp) == -1)
		just_error("exec error");
}

void	last_child(t_data *all, int *fd, char *argv[], char *envp[])
{
	all->outfile = open(argv[4], O_RDWR | O_CREAT | O_TRUNC, 0644);
	if (all->outfile == -1)
		just_error("file open error");
	all->order2 = check_order(all->path, all->cmd2[0]);
	close(fd[1]);
	if (dup2(all->outfile, 1) == -1)
		just_error("dup error");
	if (dup2(fd[0], 0) == -1)
		just_error("dup error");
	close(fd[0]);
	close(all->outfile);
	if (execve(all->order2, all->cmd2, envp) == -1)
		just_error("exec error");
}
