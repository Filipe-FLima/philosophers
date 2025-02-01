/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_simulation.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: filipe <filipe@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 17:06:46 by flima             #+#    #+#             */
/*   Updated: 2025/02/01 23:15:02 by filipe           ###   ########.fr       */
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
	if (pthread_create(&waiter, NULL, manager, &data) != 0)
		// clean_all(data);
	data->start_simulation = get_current_time();
	data->enjoy_it = true;
	i = -1;
	if (pthread_join(waiter, NULL) != 0)
		// clean_all(data);
	while (++i < data->nbr_philos)
	{
		pthread_join(data->philos[i].thread_id, NULL);
			// clean_all(data);
	}
}
