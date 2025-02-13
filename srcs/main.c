/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flima <flima@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/25 17:54:43 by flima             #+#    #+#             */
/*   Updated: 2025/02/13 21:38:23 by flima            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	print_status(t_simulation *data, t_philos *philo, char *st, int ck)
{
	long int	time;

	pthread_mutex_lock(&data->print_status);
	time = get_current_time(data) - data->start_simulation;
	if (is_alive(philo) || ck == 1)
		printf("%ld %d %s\n", time, philo->philo_id, st);
	pthread_mutex_unlock(&data->print_status);
}

static void	parse_args(int argc, char **argv, t_simulation *data)
{
	data->nbr_philos = ft_atol(argv[1]);
	data->time_to_die = ft_atol(argv[2]) * 1e3;
	data->time_to_eat = ft_atol(argv[3]) * 1e3;
	data->time_to_sleep = ft_atol(argv[4]) * 1e3;
	if (data->time_to_die < 6e4 || data->time_to_die < 6e4 \
		|| data->time_to_sleep < 6e4)
	{
		ft_putendl_fd("Error\nUse timestamps greater than 60ms", 2);
		exit(1);
	}
	if (data->nbr_philos > 200)
	{
		ft_putendl_fd("Error\nNumber of philos cannot be greater than 200", 2);
		exit(1);
	}
	if (argc == 6)
		data->nbr_max_meals = ft_atol(argv[5]);
	else
		data->nbr_max_meals = -1;
}

int	main(int argc, char **argv)
{
	t_simulation	data;

	validate_args(argc, argv);
	parse_args(argc, argv, &data);
	init_data(&data);
	start_dinner(&data);
	free_simulation(&data, 0);
	return (0);
}
