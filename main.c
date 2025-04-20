/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abnemili <abnemili@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 14:37:33 by abnemili          #+#    #+#             */
/*   Updated: 2025/04/20 15:16:10 by abnemili         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"



int	main(int ac, char **av)
{
	// t_program	program;
	// t_philo		philos[PHILO_MAX];
	// pthread_mutex_t	forks[PHILO_MAX];
	
	if (ac != 6)
		return (ft_putstr("Error\nWrong argument number\n"), 1);
	if (check_valide_av(av) == 1)
		exit(1);
	
}
