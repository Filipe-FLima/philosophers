/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flima <flima@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/25 15:36:06 by flima             #+#    #+#             */
/*   Updated: 2025/02/08 23:12:58 by flima            ###   ########.fr       */
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

typedef pthread_mutex_t			t_mutex;
typedef struct s_forks			t_forks;
typedef struct s_philos			t_philos;
typedef struct s_simulation		t_simulation;

typedef enum e_status
{
	INIT,
	CREATE,
	JOIN,
}			t_status;

struct	s_forks
{
	t_mutex	fork;
	int		fork_id;	
};

struct	s_simulation
{
	int			nbr_philos;
	int			time_to_die;
	int			time_to_eat;
	int			time_to_sleep;
	int			nbr_max_meals;
	long		start_simulation;
	bool		end_simulation;
	bool		enjoy_it;
	t_mutex		eating;
	t_mutex		is_dead;
	t_mutex		is_full;
	t_mutex		print_status;
	t_forks		*forks;
	t_philos	*philos;
};

struct	s_philos
{
	int				philo_id;
	t_forks			*first_fork;
	t_forks			*second_fork;
	int				nbr_meals;
	bool			full;
	long			last_meal_time;
	pthread_t		thread_id;
	t_simulation	*simulation;
};

//utils functions
int			ft_isdigit(int c);
long		ft_atol(const char *nptr);
void		ft_putendl_fd(char	*s, int fd);
long int	get_current_time(void);
void		print_status(t_simulation *data, t_philos *philo, char *status);
void		safe_mutex(t_simulation *data, t_mutex *mutex, t_status	status);
//error functions
void		validate_args(int argc, char **argv);
//init function
void		init_data(t_simulation *data);
// free functions
void		free_error_exit(t_simulation *data, int out);
void		free_simulation(t_simulation *data, int out);
// simulation
void		start_dinner(t_simulation *data);
void		*routine(void	*ph);
void		*manager(void *simulation);
bool		is_alive(t_philos *philo);

#endif