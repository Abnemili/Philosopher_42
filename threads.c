/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abnemili <abnemili@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/01 09:32:00 by abnemili          #+#    #+#             */
/*   Updated: 2025/05/02 20:56:21 by abnemili         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	*philo_routine(void *pointer)
{
	t_philo	*philo;

	philo = (t_philo *)pointer;
	if (philo->id % 2 == 0)
		ft_usleep(1);
	while (!dead_loop(philo))
	{
		eat(philo);
		dream(philo);
		think(philo);
	}
	return (pointer);
}

int thread_creation (t_program *program, my_mutex *forks)
{
    pthread_t   obserever;
    int         i;

    if (pthread_create(&obserever, NULL, &monitor, program->philos) != 0)
        destroy_all("thread creation faild", program, forks);
    i = 0;
    while (i < program->philos[0].num_of_philos)
    {
        if (pthread_create(&program->philos[i].thread, NULL, &philo_routine,
                &program->philos[i]) != 0)
            destroy_all("thread creation faild", program, forks);
        i++;
    }
    i = 0;
    if (pthread_join(obserever, NULL) != 0)
        destroy_all("thread join error", program, forks);
    while (i < program->philos[0].num_of_philos)
    {
        if (pthread_join(program->philos[i].thread, NULL) != 0)
            destroy_all("thread join error",program, forks);
        i++;
    }
    return ;
    
}