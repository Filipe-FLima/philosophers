/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manager.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flima <flima@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 21:34:24 by filipe            #+#    #+#             */
/*   Updated: 2025/02/06 21:54:11 by flima            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

static bool is_all_full(t_simulation *data)
{
	int 	i;

	i = 0;
	pthread_mutex_lock(&data->is_full);
	while (i < data->nbr_philos)
	{

		if (!data->philos[i].full)
		{
			pthread_mutex_unlock(&data->is_full);
			return (false);
		}
		i++;
	}
	pthread_mutex_unlock(&data->is_full);
	return (true);
}

static bool is_dead(t_philos *philo)
{
	long	int		current_time;
	long	int		time_diff;
	long	int		mls_die;

	// pthread_mutex_lock(&philo->simulation->eating);
	current_time = get_current_time();
	time_diff = current_time - philo->last_meal_time;
	mls_die = philo->simulation->time_to_die / 1e3;
	// pthread_mutex_unlock(&philo->simulation->eating);
	if (time_diff > mls_die)
	{
		return (true);
	}
	return (false);
}

static	void	end_simulation(t_simulation *data)
{
	pthread_mutex_lock(&data->is_dead);
	data->end_simulation = true;
	pthread_mutex_unlock(&data->is_dead);
}
void    *manager(void *simulation)
{
    t_philos        *philo;
    t_simulation    *data;
    int             i;
	
	// usleep(1000);
    data = (t_simulation *)simulation;
    philo = data->philos;
    while (!is_all_full(data))
    {
        i = 0;
        while (i < data->nbr_philos)
        {
            if (is_dead(&philo[i]))
            {
                end_simulation(data);
                print_status(data, &philo[i], "is dead.");
				return (NULL);
            }
            i++;
        }
        usleep(1000);
    }
    return (NULL);
}
