/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flima <flima@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/25 17:54:43 by flima             #+#    #+#             */
/*   Updated: 2025/01/25 18:23:33 by flima            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

static void get_args(int argc, char **argv, t_core *data)
{
	data->nbr_philos = ft_atol(argv[1]);
	data->time_to_die = ft_atol(argv[2]);
	data->time_to_eat = ft_atol(argv[3]);
	data->time_to_sleep = ft_atol(argv[4]);
	data->nbr_max_meals = -1;
	if (argc == 6)
		data->nbr_max_meals = ft_atol(argv[5]);
}


int	main(int argc, char **argv)
{
	t_core	data;
	
	validate_args(argc, argv);
	get_args(argc, argv, &data);
	return (0);
}