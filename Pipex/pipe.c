/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: micha <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 20:10:45 by micha             #+#    #+#             */
/*   Updated: 2025/03/11 20:10:47 by micha            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipe.h"

void	handle_parent_process(int *fd, pid_t pid1, pid_t pid2)
{
	close(fd[0]);
	close(fd[1]);
	waitpid(pid1, NULL, 0);
	waitpid(pid2, NULL, 0);
}

void	pipe_maker(t_data *all, char *argv[], char *envp[])
{
	pid_t	pid1;
	pid_t	pid2;
	int		fd[2];

	pipe(fd);
	pid2 = -1;
	pid1 = fork();
	if (pid1 == -1)
		just_error("pid error");
	else if (pid1 == 0)
		first_child(all, fd, argv, envp);
	else
	{
		pid1 = fork();
		if (pid1 == -1)
			just_error("pid error");
		else if (pid1 == 0)
			last_child(all, fd, argv, envp);
		else
			handle_parent_process(fd, pid1, pid2);
	}
}

void	allfree(char **all)
{
	int	i;

	i = 0;
	while (all[i])
	{
		free(all[i]);
		i++;
	}
	free(all);
}

int	main(int argc, char *argv[], char *envp[])
{
	t_data	all;

	if (argc != 5)
		just_error("input count");
	all.cmd1 = ft_split(argv[2], ' ');
	all.cmd2 = ft_split(argv[3], ' ');
	all.path = path_maker(envp);
	pipe_maker(&all, argv, envp);
	allfree(all.path);
	allfree(all.cmd1);
	allfree(all.cmd2);
	return (0);
}
