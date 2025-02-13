/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flima <flima@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/25 18:14:32 by flima             #+#    #+#             */
/*   Updated: 2025/02/13 21:40:18 by flima            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	*safe_malloc(size_t bytes, t_simulation *data)
{
	void	*ptr;

	ptr = malloc(bytes);
	if (ptr == NULL)
	{
		ft_putendl_fd("Error\nMemory allocation failed.", 2);
		free_error_exit(data, 1);
	}
	return (ptr);
}

long int	get_current_time(t_simulation *data)
{
	struct timeval	time;

	pthread_mutex_lock(&data->get_time);
	gettimeofday(&time, NULL);
	pthread_mutex_unlock(&data->get_time);
	return ((time.tv_sec * 1000) + (time.tv_usec / 1000));
}

static void	assign_forks(t_philos *philo, t_forks *forks, int i)
{
	int	nbr_philos;

	nbr_philos = philo->simulation->nbr_philos;
	if (philo->philo_id % 2 == 0)
	{
		philo->first_fork = &forks[i];
		philo->second_fork = &forks[(i + 1) % nbr_philos];
	}
	else
	{
		philo->first_fork = &forks[(i + 1) % nbr_philos];
		philo->second_fork = &forks[i];
	}
}

static void	init_philo(t_simulation *data)
{
	int	i;

	i = -1;
	while (++i < data->nbr_philos)
	{
		data->philos[i].philo_id = i + 1;
		data->philos[i].full = false;
		data->philos[i].nbr_meals = 0;
		data->philos[i].last_meal_time = get_current_time(data);
		data->philos[i].simulation = data;
		assign_forks(&data->philos[i], data->forks, i);
	}
}

void	init_data(t_simulation *data)
{
	int	i;

	i = -1;
	data->end_simulation = false;
	data->enjoy_it = false;
	data->philos = NULL;
	data->forks = NULL;
	data->philos = safe_malloc(data->nbr_philos * sizeof(t_philos), data);
	data->forks = safe_malloc(data->nbr_philos * sizeof(t_forks), data);
	while (++i < data->nbr_philos)
	{
		safe_mutex(data, &data->forks[i].fork, INIT);
		data->forks[i].fork_id = i;
	}
	safe_mutex(data, &data->print_status, INIT);
	safe_mutex(data, &data->eating, INIT);
	safe_mutex(data, &data->is_full, INIT);
	safe_mutex(data, &data->is_dead, INIT);
	safe_mutex(data, &data->get_time, INIT);
	init_philo(data);
}
