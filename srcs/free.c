/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flima <flima@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 17:47:36 by filipe            #+#    #+#             */
/*   Updated: 2025/02/13 21:36:17 by flima            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	free_error_exit(t_simulation *data, int out)
{
	t_forks		*forks;
	t_philos	*philos;

	forks = data->forks;
	philos = data->philos;
	if (forks)
		free(forks);
	if (philos)
		free(philos);
	exit(out);
}

void	free_simulation(t_simulation *data, int out)
{
	int	i;

	i = -1;
	while (++i < data->nbr_philos)
		pthread_mutex_destroy(&data->forks[i].fork);
	pthread_mutex_destroy(&data->print_status);
	pthread_mutex_destroy(&data->eating);
	pthread_mutex_destroy(&data->is_full);
	pthread_mutex_destroy(&data->is_dead);
	pthread_mutex_destroy(&data->get_time);
	free_error_exit(data, out);
}
