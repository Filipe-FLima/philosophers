/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors_handling.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flima <flima@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/25 17:13:33 by flima             #+#    #+#             */
/*   Updated: 2025/02/08 23:15:20 by flima            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

static void	nbr_of_args(int argc)
{
	if (argc < 5 || argc > 6)
	{
		ft_putendl_fd("Erro\nInvalid number of arguments.", 2);
		exit(1);
	}
}

static	void	check_content_args(char **argv)
{
	int	i;
	int	j;

	i = 1;
	while (argv[i])
	{
		j = 0;
		if (argv[i][j] == '\0')
		{
			ft_putendl_fd("Error\nEmpty argument.", 2);
			exit(1);
		}
		while (argv[i][j])
		{
			if (!ft_isdigit(argv[i][j]))
			{
				ft_putendl_fd("Error\nWrong type of argument.", 2);
				exit(1);
			}
			j++;
		}
		i++;
	}
}

static void	check_sizeof_args(char **argv)
{
	long	value;
	int		i;

	i = 1;
	while (argv[i])
	{
		value = ft_atol(argv[i]);
		if (value > 2147483647 || value < 0)
		{
			ft_putendl_fd("Error\nInvalid size of input number.", 2);
			exit(1);
		}
		i++;
	}
}

void	validate_args(int argc, char **argv)
{
	nbr_of_args(argc);
	check_sizeof_args(argv);
	check_content_args(argv);
}
