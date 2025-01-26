/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: filipe <filipe@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/25 18:14:32 by flima             #+#    #+#             */
/*   Updated: 2025/01/26 22:07:55 by filipe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void    *safe_malloc(size_t bytes, t_simulation *data)
{
    void    *ptr;
    
    ptr = malloc(bytes);
    if (ptr == NULL)
    {
        ft_putendl_fd("Error\nMemory allocation failed.");
        free_exit(data);// to do
    }
    return (ptr);
}
void    init_data(t_simulation *data)
{
        
}

void    free_error_exit(t_simulation *data)
{
    t_forks *forks;
    
    forks = data->forks;
    if (forks)
    {
        
    }
}