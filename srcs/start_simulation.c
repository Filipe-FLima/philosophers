/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_simulation.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flima <flima@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 17:06:46 by flima             #+#    #+#             */
/*   Updated: 2025/02/08 23:34:59 by flima            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

static void	safe_philo_thread(t_simulation *data, int i, t_status status)
{
	int	j;

	if (status == CREATE)
	{
		j = pthread_create(&data->philos[i].thread_id, NULL, \
			routine, &data->philos[i]);
		if (j != 0)
		{
			ft_putendl_fd("Error\nCan not create the philo thread.", 2);
			free_simulation(data, 1);
		}
	}
	else if (status == JOIN)
	{
		if (pthread_join(data->philos[i].thread_id, NULL) != 0)
		{
			ft_putendl_fd("Error\nCan not join the philo thread.", 2);
			free_simulation(data, 1);
		}
	}
}

void	start_dinner(t_simulation *data)
{
	int			i;
	pthread_t	waiter;

	if (data->nbr_max_meals == 0)
		return ;
	i = -1;
	while (++i < data->nbr_philos)
		safe_philo_thread(data, i, CREATE);
	if (pthread_create(&waiter, NULL, manager, data) != 0)
	{
		ft_putendl_fd("Error\nCan not create the manager thread.", 2);
		free_simulation(data, 1);
	}
	data->start_simulation = get_current_time();
	data->enjoy_it = true;
	if (pthread_join(waiter, NULL) != 0)
	{
		ft_putendl_fd("Error\nCan not join the manager thread.", 2);
		free_simulation(data, 1);
	}
	i = -1;
	while (++i < data->nbr_philos)
		safe_philo_thread(data, i, JOIN);
}
