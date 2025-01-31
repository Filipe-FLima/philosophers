/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flima <flima@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/25 18:14:32 by flima             #+#    #+#             */
/*   Updated: 2025/01/29 22:02:53 by flima            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void    *safe_malloc(size_t bytes, t_simulation *data)
{
    void    *ptr;
    
    ptr = malloc(bytes);
    if (ptr == NULL)
    {
        ft_putendl_fd("Error\nMemory allocation failed.", 2);
        free_exit(data);// to do
    }
    return (ptr);
}

long	int	get_current_time(void)
{
	struct timeval	time;

	gettimeofday(&time, NULL); // check erros return
	return ((time.tv_sec * 1000) + (time.tv_usec / 1000));
}

static	void	assign_forks(t_philos *philos, t_forks *forks, int i)
{
	int	nbr_philos;
	
	nbr_philos = philos->simulation->nbr_philos;
	philos->first_fork = &forks[(i + 1) % nbr_philos];
	philos->second_fork = &forks[i];
	if (philos->philo_id % 2)
	{
		philos->first_fork = &forks[i];
		philos->second_fork = &forks[(i + 1) % nbr_philos];
	}
}
static	void	init_philo(t_simulation *data)
{
	int	i;

	i = -1;
	while (++i < data->nbr_philos)
	{
		data->philos[i].philo_id = i + 1;
		data->philos[i].full= false;
		data->philos[i].nbr_meals = 0;
		data->philos[i].last_meal_time = get_current_time();
		data->philos[i].simulation = data;
		assign_forks(data->philos, data->forks, i);
	}
}
void    init_data(t_simulation *data)
{
	int	i;
	
	i = -1;
    data->end_simulation = false;
	data->enjoy_it = false;
    data->philos = safe_malloc(data->nbr_philos * sizeof(t_philos), data);
    data->forks = safe_malloc(data->nbr_philos * sizeof(t_forks), data);
    while (++i < data->nbr_philos)
	{
		pthread_mutex_init(&data->forks[i].fork, NULL);
		data->forks[i].fork_id = i;
	}
	pthread_mutex_init(&data->print_status, NULL);//check for erros return?
	pthread_mutex_init(&data->eating, NULL);
	init_philo(data);
}

void    free_error_exit(t_simulation *data) //change name
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