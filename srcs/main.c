/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: filipe <filipe@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/25 17:54:43 by flima             #+#    #+#             */
/*   Updated: 2025/02/01 22:18:19 by filipe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

static void parse_args(int argc, char **argv, t_simulation *data)
{
	data->nbr_philos = ft_atol(argv[1]);
	data->time_to_die = ft_atol(argv[2]) * 1e3;
	data->time_to_eat = ft_atol(argv[3]) * 1e3;
	data->time_to_sleep = ft_atol(argv[4]) * 1e3;
	if (data->time_to_die < 6e4 || data->time_to_die < 6e4 \
		|| data->time_to_sleep < 6e4)
	{
		ft_putendl_fd("Erro\nUse timestamps greater tran 60ms", 2);
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
	start_dinner(&data); //to do
	// clean_simulation();//to do
	return (0);
}