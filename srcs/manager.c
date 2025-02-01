/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manager.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: filipe <filipe@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 21:34:24 by filipe            #+#    #+#             */
/*   Updated: 2025/02/01 22:14:21 by filipe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

static bool is_all_full(t_simulation *data)
{
	int i;

	i = 0;
	while (i < data->nbr_philos)
	{
		if (!data->philos[i].full)
			return (false);
		i++;
	}
	return (true);
}

static bool is_dead(t_philos *philo)
{
	long	int		current_time;
	long	int		time_diff;

	current_time = get_current_time();
	time_diff = current_time - philo->last_meal_time;
	if (time_diff > philo->simulation->time_to_die)
		return (true);
	return (false);
}

void    *manager(void *simulation)
{
    t_philos        *philo;
    t_simulation    *data;
    int             i;

    data = (t_simulation *)simulation;
    philo = data->philos;
    while (!is_all_full(data))
    {
        i = 0;
        while (i < data->nbr_philos)
        {
            if (is_dead(&philo[i]))
            {
                data->end_simulation = true;
                print_status(data, &philo[i], "is dead.");
            }
            i++;
        }
        usleep(1000);
    }
    return (NULL);
}
