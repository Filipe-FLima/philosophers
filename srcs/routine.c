/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flima <flima@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 21:05:34 by flima             #+#    #+#             */
/*   Updated: 2025/01/29 22:11:38 by flima            ###   ########.fr       */
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

void	static	eating(t_philos *philo)
{
	if (!philo->simulation->end_simulation)
		print_status(philo->simulation, philo, "is eating");
	usleep(philo->simulation->time_to_eat);
}

void	static	eat(t_philos *philo)
{
	pthread_mutex_lock(philo->first_fork);
	print_status(philo->simulation, philo, "has taken a fork");
	pthread_mutex_lock(philo->second_fork);
	print_status(philo->simulation, philo, "has taken a fork");
	pthread_mutex_lock(&philo->simulation->eating);
	philo->last_meal_time = get_current_time();
	philo->nbr_meals++;
	pthread_mutex_unlock(&philo->simulation->eating);
	eating(philo);
	pthread_mutex_unlock(philo->first_fork);
	pthread_mutex_unlock(philo->second_fork);
}
void	routine(void	*ph)
{
	t_philos	*philo;

	philo = (t_philos *)ph;
	while (!philo->simulation->enjoy_it)
		;
	while (!philo->simulation->end_simulation)
	{
		eat(philo);
		if (philo->nbr_meals == philo->simulation->nbr_max_meals)
			return ;
		sleep(philo);
		thinking(philo);
	}
}