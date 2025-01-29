/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: filipe <filipe@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/25 18:14:32 by flima             #+#    #+#             */
/*   Updated: 2025/01/28 20:17:58 by filipe           ###   ########.fr       */
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
void    init_data(t_simulation *data)
{
    data->end_simulation = false;
    data->philos = safe_malloc(data->nbr_philos * sizeof(t_philos), data);
    data->forks = safe_malloc(data->nbr_philos * sizeof(t_forks), data);
    
}

void    free_error_exit(t_simulation *data)
{
    t_forks *forks;
    
    forks = data->forks;
    if (forks)
    {
        
    }
}