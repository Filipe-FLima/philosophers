/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_simulation.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flima <flima@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 17:06:46 by flima             #+#    #+#             */
/*   Updated: 2025/01/29 20:35:17 by flima            ###   ########.fr       */
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
		if (pthread_create(&data->philos[i].philo_id, NULL, routine,
			&data->philos[i]) != 0)
			clean_all(data); //todo
	}
	if (pthread_create(&waiter, NULL, manager, &data) != 0)
		clean_all(data);
	data->start_simulation = get_current_time();
	data->enjoy_it = true;
	i = -1;
	if (pthread_join(waiter, NULL) != 0)
		clean_all(data);
	while (++i < data->nbr_philos)
	{
		if (pthread_join(data->philos[i].philo_id, NULL) != 0)
			clean_all(data);
	}
}
