/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flima <flima@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 21:05:34 by flima             #+#    #+#             */
/*   Updated: 2025/02/06 22:02:31 by flima            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

static	void	thinking(t_philos *philo)
{
	if (!philo->simulation->end_simulation)
		print_status(philo->simulation, philo, "is thinking");
}

static	void	sleeping(t_philos *philo)
{
	if (!philo->simulation->end_simulation)
		print_status(philo->simulation, philo, "is sleeping");
	usleep(philo->simulation->time_to_sleep);
}

static	void	eating(t_philos *philo)
{
	if (!philo->simulation->end_simulation)
		print_status(philo->simulation, philo, "is eating");
	usleep(philo->simulation->time_to_eat);
}

static	int	eat(t_philos *philo)
{
	pthread_mutex_lock(&philo->first_fork->fork);
	print_status(philo->simulation, philo, "has taken a fork");
	if (philo->simulation->nbr_philos == 1)
	{
		pthread_mutex_unlock(&philo->first_fork->fork);
		return (1);
	}
	pthread_mutex_lock(&philo->second_fork->fork);
	print_status(philo->simulation, philo, "has taken a fork");
	// pthread_mutex_lock(&philo->simulation->eating);
	eating(philo);
	philo->last_meal_time = get_current_time();
	philo->nbr_meals++;
	// pthread_mutex_unlock(&philo->simulation->eating);
	pthread_mutex_unlock(&philo->first_fork->fork);
	pthread_mutex_unlock(&philo->second_fork->fork);
	return (0);
}

static bool	is_alive(t_philos *philo)
{
	bool	alive;
	
    pthread_mutex_lock(&philo->simulation->is_dead);
    alive = !philo->simulation->end_simulation;
    pthread_mutex_unlock(&philo->simulation->is_dead);
    return alive;
}
void	*routine(void	*ph)
{
	t_philos	*philo;
	philo = (t_philos *)ph;
	while (!philo->simulation->enjoy_it)
		usleep(10);
	while (is_alive(philo))
	{
		if (eat(philo) == 1)
			return (NULL);
		if (philo->nbr_meals == philo->simulation->nbr_max_meals)
		{
			pthread_mutex_lock(&philo->simulation->is_full);
			philo->full = true;
			pthread_mutex_unlock(&philo->simulation->is_full);
			return (NULL);
		}	
		sleeping(philo);
		thinking(philo);
	}
	return (NULL);
}
