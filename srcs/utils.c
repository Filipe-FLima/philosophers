/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flima <flima@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/25 16:35:09 by flima             #+#    #+#             */
/*   Updated: 2025/02/08 23:32:38 by flima            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	ft_isdigit(int c)
{
	if ('0' <= c && c <= '9')
		return (1);
	return (0);
}

long	ft_atol(const char *nptr)
{
	long	nb;
	long	sign;
	long	i;

	sign = 1;
	nb = 0;
	i = 0;
	while (nptr[i] == ' ' || (nptr[i] >= '\t'
			&& nptr[i] <= '\r'))
		i++;
	if (nptr[i] == '+' || nptr[i] == '-')
	{
		if (nptr[i] == '-')
			sign = -sign;
		i++;
	}
	while (ft_isdigit(nptr[i]))
	{
		nb = nb * 10 + (nptr[i] - '0');
		i++;
	}
	return (nb * sign);
}

bool	is_alive(t_philos *philo)
{
	bool	alive;

	pthread_mutex_lock(&philo->simulation->is_dead);
	alive = !philo->simulation->end_simulation;
	pthread_mutex_unlock(&philo->simulation->is_dead);
	return (alive);
}

void	ft_putendl_fd(char	*s, int fd)
{
	size_t	len;

	len = 0;
	if (s == NULL)
		return ;
	while (s[len])
		len++;
	write(fd, s, len);
	write(fd, "\n", 1);
}

void	safe_mutex(t_simulation *data, t_mutex *mutex, t_status	status)
{
	if (status == INIT)
	{
		if (pthread_mutex_init(mutex, NULL) != 0)
		{
			ft_putendl_fd("Error\nCan not init the mutex.", 2);
			free_simulation(data, 1);
		}
	}
}
