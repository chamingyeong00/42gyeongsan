/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: micha <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 20:10:53 by micha             #+#    #+#             */
/*   Updated: 2025/03/11 20:10:55 by micha            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPE_H
# define PIPE_H
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <sys/wait.h>
# include <unistd.h>
# include <fcntl.h>
# include "./libft/libft.h"

typedef struct s_data
{
	int		infile;
	int		outfile;
	char	**cmd1;
	char	**cmd2;
	char	**path;
	char	*order1;
	char	*order2;
}	t_data;

char	**ft_split2(char const *s, char c);
void	just_error(char *s);
char	**path_maker(char *envp[]);
char	*check_order(char **path, char *cmd);
void	first_child(t_data *all, int *fd, char *argv[], char *envp[]);
void	last_child(t_data *all, int *fd, char *argv[], char *envp[]);

#endif
