/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: filipe <filipe@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/25 15:36:06 by flima             #+#    #+#             */
/*   Updated: 2025/01/26 18:45:25 by filipe           ###   ########.fr       */
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
# include <stdbool.h>

typedef pthread_mutex_t t_mutex;
typedef struct s_forks t_forks;
typedef struct s_philos t_philos;
typedef struct s_simulation t_simulation;

typedef	struct s_forks
{
	t_mutex	fork;
	int		fork_id;	
}			t_forks;

struct s_simulation
{
	int			nbr_philos;
	int			time_to_die;
	int			time_to_eat;
	int			time_to_sleep;
	int			nbr_max_meals;
	long		start_simulation;
	bool		end_simulation;
	t_forks		*forks;
	t_philos	*philos;
};

 
struct s_philos
{
	int				philo_id;
	t_forks			*left_fork;
	t_forks			*right_fork;
	int				nbr_meals;
	bool			full;
	long			last_meal_time;
	pthread_t 		thread_id;
	t_simulation	*simulation;
};

//utils functions
int		ft_isdigit(int c);
long	ft_atol(const char *nptr);
void	ft_putendl_fd(char	*s, int fd);
size_t	ft_strlen(const char *s);
//error functions
void	validate_args(int argc, char **argv);

#endif