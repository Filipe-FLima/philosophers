/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_simulation.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flima <flima@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 17:06:46 by flima             #+#    #+#             */
/*   Updated: 2025/02/04 22:30:01 by flima            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	start_dinner(t_simulation *data)
{
	int	i;
	pthread_t	waiter;
	if (data->nbr_max_meals == 0)
		return ;
	i = -1;
	while (++i < data->nbr_philos)
	{
		pthread_create(&data->philos[i].thread_id, NULL, routine, &data->philos[i]);
			// clean_all(data); //todo
	}
	pthread_create(&waiter, NULL, manager, &data);
		// clean_all(data);
	data->start_simulation = get_current_time();
	i = -1;
	data->enjoy_it = true;
	pthread_join(waiter, NULL);
		// clean_all(data);
	while (++i < data->nbr_philos)
	{
		pthread_join(data->philos[i].thread_id, NULL);
			// clean_all(data);
	}
}
