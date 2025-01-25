/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flima <flima@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/25 15:36:06 by flima             #+#    #+#             */
/*   Updated: 2025/01/25 17:56:45 by flima            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <string.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/time.h>
# include <pthread.h>

typedef struct s_core
{
	int	nbr_philos;
	int	time_to_die;
	int	time_to_eat;
	int	time_to_sleep;
	int	nbr_max_meals;
}		t_core;


//utils functions
int		ft_isdigit(int c);
long	ft_atol(const char *nptr);
void	ft_putendl_fd(char	*s, int fd);
size_t	ft_strlen(const char *s);
//error functions
void	validate_args(int argc, char **argv);

#endif