/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abnemili <abnemili@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 14:37:33 by abnemili          #+#    #+#             */
/*   Updated: 2025/05/03 20:48:52 by abnemili         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"



int	main(int ac, char **av)
{
	t_program	program;
	t_philo		philos[PHILO_MAX];
	pthread_mutex_t	forks[PHILO_MAX];
	
	if (ac != 6)
		return (ft_putstr("Error\nWrong argument number\n"), 1);
	if (check_valide_av(av) == 1)
		exit(1);
	init_the_program(&program, philos);
	init_the_forks(forks,ft_atoi(av[1]));
	init_philos(philos, &program, forks, av);
	thread_creation(&program, forks);
	destroy_all(NULL, &program, forks);
	return (0);
}
