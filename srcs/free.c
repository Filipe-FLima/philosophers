/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: filipe <filipe@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 17:47:36 by filipe            #+#    #+#             */
/*   Updated: 2025/02/02 17:58:07 by filipe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void    free_error_exit(t_simulation *data)
{
    t_forks 	*forks;
	t_philos	*philos;
    
    forks = data->forks;
	philos = data->philos;
    if (forks)
		free(forks);
	if (philos)
		free(philos);
	ft_putendl_fd("Error\nMemory allocation failed.", 2);
	exit(1);
}

void    clean_all(t_simulation *data)
{
    int i;

    i = -1;
    while (++i < data->nbr_philos)
        pthread_mutex_destroy(&data->forks[i].fork);
    pthread_mutex_destroy(&data->print_status);
    pthread_mutex_destroy(&data->eating);
    free_error_exit(data);
}