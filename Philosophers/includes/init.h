/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: micha <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/26 16:08:39 by micha             #+#    #+#             */
/*   Updated: 2025/06/26 16:08:43 by micha            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INIT_H
# define INIT_H

# include "philo.h"

void	init_philos(t_engine *en, t_philo *philos, t_mutex *forks, char **argv);
void	init_forks(t_engine *engine, t_mutex *forks, int count);
void	init_engine(t_engine *engine, t_philo *philos, t_mutex *forks);

#endif   /* INIT_H */
