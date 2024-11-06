/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util_str.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chsung <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 22:51:09 by chsung            #+#    #+#             */
/*   Updated: 2024/08/26 22:51:11 by chsung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTIL_STR_H
# define UTIL_STR_H

# include <unistd.h>
# include <stdlib.h>
# include "struct.h"

void	bsq_str_free(t_str *str);
t_str	*bsq_read_line(int fd);

#endif
