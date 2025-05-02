/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abnemili <abnemili@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 17:14:58 by abnemili          #+#    #+#             */
/*   Updated: 2025/05/02 20:14:51 by abnemili         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

// init the forks mutexes
void init_the_forks(my_mutex *forks, int num_of_philos)
{
    int i;

    i = 0;
    while (i < num_of_philos)
    {
        pthread_mutex_init(&forks[i], NULL);
        i++;
    }   
}

void init_the_program(t_program *program, t_philo *philos)
{
    program->dead_flag = 0;
    program->philos = philos;
    pthread_mutex_init(&program->write_lock, NULL);
    pthread_mutex_init(&program->dead_lock, NULL);
    pthread_mutex_init(&program->meal_lock, NULL);
}

void  init_input(t_philo*philo, char **av)
{
    philo->time_to_die = ft_atoi(av[2]);
    philo->time_to_eat = ft_atoi(av[3]);
    philo->time_to_sleep = ft_atoi(av[4]);
    if (av[5])
        philo->num_times_to_eat = ft_atoi(av[5]);
    else 
        philo->num_times_to_eat = -1;
}

void init_philos(t_philo *philos, t_program *program, my_mutex *forks,
    char **av)
{
    int i;

    i = 0;
    while (i < ft_atoi(av[1]))
    {
        philos[i].id =  i + 1;
        philos[i].eating = 0;
        init_input(&philos[i], av);
        philos[i].start_time = get_current_time();
        philos[i].last_meal = get_current_time();
        philos[i].write_lock = &program->write_lock;
        philos[i].dead_lock = &program->dead_lock;
        philos[i].meal_lock = &program->meal_lock;
        philos[i].dead = &program->dead_flag;
        philos[i].l_fork = &forks[i];
        if (i == 0)
            philos[i].r_fork = &forks[philos[i].num_of_philos - 1];
        else
            philos[i].r_fork = &forks[i - 1];
        i++;
    }    
}